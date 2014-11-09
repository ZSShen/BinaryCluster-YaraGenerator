#ifndef _CLUSTER_H_
#define _CLUSTER_H_


typedef struct _CONFIG {
    int  cfgParallelity;
    int  cfgBlkCount;
    int  cfgBlkSize;
    char *cfgPathRoot;
} CONFIG;


typedef struct _CLUSTER {
    CONFIG *cfgTask;
    
    int (*init_cluster_ctx)   (struct _CLUSTER*, CONFIG*);
    int (*deinit_cluster_ctx) (struct _CLUSTER*);
    int (*generate_group)     (struct _CLUSTER*);
    int (*generate_pattern)   (struct _CLUSTER*);
} CLUSTER;


#endif
