
cmake_minimum_required(VERSION 2.8)
set(CMAKE_INSTALL_PREFIX "")
project(CLUSTER)


# Define the paths of engine and plugin source trees.
set(DIR_PLUGIN "${CMAKE_CURRENT_SOURCE_DIR}/plugin")
set(DIR_ENGINE "${CMAKE_CURRENT_SOURCE_DIR}/engine")


# Prepare the cached varaibles for the subsequent CMakeLists.txt.
set(BUILD_TYPE_DEBUG "Debug")
set(LIB_TYPE_DYNAMIC "Dynamic")
set(MSG_BUILD_TYPE "Default Debug Build")
set(MSG_LIB_TYPE "Default Build Dynamic Library")

if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE ${BUILD_TYPE_DEBUG} CACHE STRING ${MSG_BUILD_TYPE} FORCE)
endif()
if (NOT DEFINED LIB_TYPE)
    set(LIB_TYPE ${LIB_TYPE_DYNAMIC} CACHE STRING ${MSG_LIB_TYPE} FORCE)
endif()


# Set the building targets.
add_subdirectory(${DIR_PLUGIN})
add_subdirectory(${DIR_ENGINE})


# Set the running target.
set(TARGET_RUN "run")
set(BIN "engine/bin/debug/cluster")
set(ARG_CONF_KEY "--conf")
set(ARG_CONF_VAL "engine/cluster.conf")
set(HINT_GDEBUG "G_DEBUG=gc-friendly")
set(HINT_GSLICE "G_SLICE=always-malloc")
add_custom_target ( ${TARGET_RUN}
    COMMAND ${HINT_GDEBUG} ${HINT_GSLICE} valgrind ${BIN} ${ARG_CONF_KEY} ${ARG_CONF_VAL}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
