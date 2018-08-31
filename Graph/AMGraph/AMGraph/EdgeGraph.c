//
//  EdgeGraph.c
//  AMGraph
//
//  Created by CXY on 2018/8/30.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "EdgeGraph.h"
#include <stdlib.h>
#include <string.h>

void createEdgeGraph(EdgeGraph **g) {
    *g = (EdgeGraph *)malloc(sizeof(EdgeGraph));
    EdgeGraph *tmp = *g;
    memset(tmp, 0, sizeof(EdgeGraph));
    
    printf("请输入边的数目：\n");
    scanf("%d", &(tmp->numEdges));
    
    for (int i=0; i<tmp->numEdges; i++) {
        printf("请输入顶点：\n");
        scanf(" %c", &(tmp->vertexes[i]));
    }
    
    for (int i=0; i<tmp->numEdges; i++) {
        printf("请输入边的起点索引、终点索引 和 边的权值：\n");
        Edge edge = tmp->edges[i];
        scanf(" %d %d %d", &edge.begin, &edge.end, &edge.weight);
    }
}
