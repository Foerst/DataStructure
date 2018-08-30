//
//  main.c
//  50- level order traversa
//
//  Created by CXY on 2018/8/6.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"

int main(int argc, const char * argv[]) {
    QueueRef queue;
    createQueue(&queue);
//    enqueue(queue, (void *)'c');
//    enqueue(queue, (void *)'b');
//    while (queue->size) {
//        char c = (char)dequeue(queue);
//        printf("dequeue===%c\n", c);
//    }
    
    // 217##9##46##3#5##
    printf("input bin tree node end with #\n");
    struct TreeNode *tree;
    createTree(&tree);
    DLR(tree);
    
//    leverOrderTraversa(tree, queue);
    
    int *columnSizes;
    int returnSize;
    int** ret = levelOrder(tree, &columnSizes, &returnSize);
    
    for (int i=0; i<returnSize; i++) {
        putchar('[');
        for (int j=0; j<columnSizes[i]; j++) {
            printf(" %i", ret[i][j]);
        }
        putchar(']');
        putchar('\n');
    }
    
    return 0;
}
