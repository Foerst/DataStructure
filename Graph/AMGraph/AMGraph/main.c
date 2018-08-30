//
//  main.c
//  AMGraph
//
//  Created by CXY on 2018/8/29.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include "AMGraph.h"
#include "ALGraph.h"

int main(int argc, const char * argv[]) {
    AMGraph g;
    CreateAMGraph(&g);
    AdMatrix_DFS(&g);

    AdMatrix_BFS(g);
    
//    GraphAdjList g;
//    CreateALGraph(&g);
//    GraphAdjList_DFS(g);
    return 0;
}
