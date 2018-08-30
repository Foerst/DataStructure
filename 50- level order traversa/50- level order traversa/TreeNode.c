//
//  TreeNode.c
//  50- level order traversa
//
//  Created by CXY on 2018/8/7.
//  Copyright © 2018年 CXY. All rights reserved.
//

#include "TreeNode.h"
#include <stdlib.h>

void createTree(struct TreeNode **tree) {
    char c;
    scanf("%c", &c);
    if (c=='#') {
        *tree = NULL;//leaf node
    } else {
        *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        (*tree)->val = c;
        createTree(&((*tree)->left));
        createTree(&((*tree)->right));
    }
}

void DLR(struct TreeNode *tree) {
    if (tree) {
        printf("DLR node : %c\n", (char)tree->val);
        DLR(tree->left);
        DLR(tree->right);
    }
}

void leverOrderTraversa(struct TreeNode *tree, QueueRef queue) {
    if (!queue || !tree) {
        return;
    }
    enqueue(queue, tree);
    while (queue->size) {
        printf(" size==%i \n", queue->size);
        int size = queue->size;
        for (int i=0; i < size; i++) {
            struct TreeNode *node = (struct TreeNode *)dequeue(queue);
            // output value
            printf("leverOrderTraversa node: %c,\n", (char)node->val);
            if (node->left) {
                enqueue(queue, node->left);
            }
            if (node->right) {
                enqueue(queue, node->right);
            }
        }
        
    }
}


int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (!root) {
        return NULL;
    }
    QueueRef queue;
    createQueue(&queue);
    enqueue(queue, root);
    *returnSize = 0;
    int **ret = (int **)malloc(1024*sizeof(int *));
    int *col = (int *)malloc(1024*sizeof(int));
    while (queue->size) {
        printf(" size==%i \n", queue->size);
        int size = queue->size;
        col[*returnSize] = size;
        ret[*returnSize] = (int *)malloc(sizeof(int)*size);
        for (int i=0; i < size; i++) {
            struct TreeNode *node = (struct TreeNode *)dequeue(queue);
            // output value
            printf("leverOrderTraversa node: %c,\n", (char)node->val);
            ret[*returnSize][i] = (char)node->val-'0';
            if (node->left) {
                enqueue(queue, node->left);
            }
            if (node->right) {
                enqueue(queue, node->right);
            }
        }
        (*returnSize)++;
        
    }
    *columnSizes = col;
    return ret;
}
