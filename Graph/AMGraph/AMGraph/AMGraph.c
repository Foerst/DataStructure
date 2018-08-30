//
//  AMGraph.c
//  AMGraph
//
//  Created by CXY on 2018/8/29.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "AMGraph.h"
#include "Queue.h"

// 建立无向网图的邻接矩阵
void CreateAMGraph(AMGraph *G){
    int i, j, k, w;
    
    printf("请输入顶点数和边数：\n");
    scanf("%d %d", &G->numVertexes, &G->numEdges);
    
    
    for( i=0; i < G->numVertexes; i++ ){
        printf("请输入顶点：\n");
        getchar();
        scanf("%c", &G->vexs[i]);
    }
    
    for( i=0; i < G->numVertexes; i++ ){
        for( j=0; j < G->numVertexes; j++ ){
            G->arc[i][j] = INFINITY;            // 邻接矩阵初始化
        }
    }
    
    for( k=0; k < G->numEdges; k++ ) {
        printf("请输入边(Vi,Vj)上的下标i,下标j和对应的权w:\n");
        scanf("%d %d %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];            // 是无向网图，对称矩阵
    }
}

static int visited[MAXVEX];

static void DFS(AMGraph *G, int j){
    visited[j] = 1;
    printf("%c ", G->vexs[j]);    // 打印顶点
    for (int i=0; i<G->numVertexes; i++) {
        if (G->arc[j][i]>0 && G->arc[j][i]<INFINITY && !visited[i]) {
            DFS(G, i);
        }
    }
}

static void reset_state(){
    for (int i=0; i<MAXVEX; i++) {
        visited[i] = 0;//0 :vertex not visited , 1: visited
    }
}

// Depth First Search of Adjacency Matrix Graph
void AdMatrix_DFS(AMGraph *G){
    reset_state();
    printf("matrix_dfs:\n");
    for (int i=0; i<G->numVertexes; i++) {
        if (!visited[i]) {// 若是连通图，只会执行一次DFS
            DFS(G, i);
        }
    }
    putchar('\n');
}

// 邻接矩阵的广度遍历算法
void AdMatrix_BFS(AMGraph G){
    QueueRef q = NULL;
    createQueue(&q);
    reset_state();
    printf("matrix_bfs:\n");
    for (int j=0; j<G.numVertexes; j++) {// 若是连通图，只会执行一次BFS
        if (!visited[j]) {
            enqueue(q, (void *)(long)j);
            while (q->size) {
                int index = (int)(long)dequeue(q);
                visited[index] = 1;
                printf("%c ", G.vexs[index]);    // 打印顶点
                for (int i=0; i<G.numVertexes; i++) {
                    int weight = G.arc[index][i];
                    if (weight>0 && weight<INFINITY &&!visited[i] ) {
                        enqueue(q, (void *)(long)i);
                    }
                }
            }
        }
    }
    putchar('\n');
    
}


