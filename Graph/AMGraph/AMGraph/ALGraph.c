//
//  ALGraph.c
//  AMGraph
//
//  Created by CXY on 2018/8/29.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "ALGraph.h"
#include <stdlib.h>

#define isLetter(a)  ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))

/*
 * 读取一个输入字符
 */
static char read_char(){
    char ch;
    
    do {
        ch = getchar();
    } while(!isLetter(ch));
    
    return ch;
}


void CreateALGraph(GraphAdjList *G){
    int i, j,weight, k;
    EdgeNode *e;
    
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    
    // 读取顶点信息，建立顶点表
    for( i=0; i < G->numVertexes; i++ ){
        printf("请输入顶点：\n");
//        G->adjList[i].data = read_char();
        // 空格%c过滤掉上一次输入的\n, 或者用getchar() ，或者用read_char()
        scanf(" %c", &G->adjList[i].data);
        G->adjList[i].firstEdge = NULL;        // 初始化置为空表
    }

    for( k=0; k < G->numEdges; k++ ){

        printf("请输入边(Vi,Vj)上的顶点序号以及权志weight：\n");
        scanf("%d %d %d", &i, &j, &weight);
        
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;                        // 邻接序号为j
        e->weight = weight;
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;                        //无向图 邻接序号为i
        e->weight = weight;
        e->next = G->adjList[j].firstEdge;
        G->adjList[j].firstEdge = e;
    }
}

static int visited[MAXVEX];

static void DFS(GraphAdjList g, int i) {
    visited[i] = 1;
    printf("%c ", g.adjList[i].data);
    EdgeNode *p = g.adjList[i].firstEdge;
    while (p) {
        if (!visited[p->adjvex]) {
            DFS(g, p->adjvex);
        }
        p = p->next;
    }
}

void GraphAdjList_DFS(GraphAdjList g){
    for (int i=0;i<g.numVertexes;i++) {
        visited[i] = 0;
    }
    printf("adjlist_dfs:\n");
    for (int i=0; i<g.numVertexes; i++) {
        if (!visited[i]) {// 若是连通图，只会执行一次DFS
            DFS(g, i);
        }
    }
    putchar('\n');
}
