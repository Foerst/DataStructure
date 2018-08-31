//
//  EdgeGraph.h
//  AMGraph
//
//  Created by CXY on 2018/8/30.
//  Copyright © 2018年 CXY. All rights reserved.
//

// 图的边集数组形式
#ifndef EdgeGraph_h
#define EdgeGraph_h

#include <stdio.h>

#define MAXVEX 100

typedef struct _t_edge{
    int begin; //边的起点顶点下标
    int end; //边的终点顶点下标
    int weight;//权
}Edge;


typedef struct _t_edge_graph{
    char vertexes[MAXVEX];
    Edge edges[MAXVEX];
    int numEdges;
}EdgeGraph;

void createEdgeGraph(EdgeGraph **g);
#endif /* EdgeGraph_h */
