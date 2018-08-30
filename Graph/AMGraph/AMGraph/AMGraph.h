//
//  AMGraph.h
//  AMGraph
//
//  Created by CXY on 2018/8/29.
//  Copyright © 2018年 CXY. All rights reserved.
//

// Adjacency Matrix of Graph 邻接矩阵

#ifndef AMGraph_h
#define AMGraph_h

#include <stdio.h>


// 时间复杂度为O(n+n^2+e)

#define MAXVEX 100            // 最大顶点数
#define INFINITY 65535        // 用65535来代表无穷大

typedef struct {
    char vexs[MAXVEX];                // 顶点表
    int arc[MAXVEX][MAXVEX];        // 邻接矩阵
    int numVertexes, numEdges;        // 图中当前的顶点数和边数
}AMGraph;

void CreateAMGraph(AMGraph *G);
void AdMatrix_DFS(AMGraph *G);
void AdMatrix_BFS(AMGraph G);
#endif /* AMGraph_h */
