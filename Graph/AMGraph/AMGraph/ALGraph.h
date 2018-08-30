//
//  ALGraph.h
//  AMGraph
//
//  Created by CXY on 2018/8/29.
//  Copyright © 2018年 CXY. All rights reserved.
//
//Ad-jacency List 邻接表

#ifndef ALGraph_h
#define ALGraph_h

#include <stdio.h>
#define MAXVEX 100
// 边表结点
typedef struct EdgeNode {
    int adjvex; //邻接点下标
    int weight; // 用于存储权值，对于非网图可以不需要
    struct EdgeNode *next; //下一个邻接点
}EdgeNode;

// 顶点表结点
typedef struct {
    char data;                    // 顶点域，存储顶点信息
    EdgeNode *firstEdge;        // 边表头指针
} VertexNode;

typedef struct {
    VertexNode adjList[MAXVEX];
    int numVertexes, numEdges;    // 图中当前顶点数和边数
} GraphAdjList;

// 建立图的邻接表结构
void CreateALGraph(GraphAdjList *G);

void GraphAdjList_DFS(GraphAdjList g);
#endif /* ALGraph_h */
