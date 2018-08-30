//
//  TreeNode.h
//  50- level order traversa
//
//  Created by CXY on 2018/8/7.
//  Copyright © 2018年 CXY. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h

#include <stdio.h>
#include "Queue.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void createTree(struct TreeNode **tree);

void DLR(struct TreeNode *tree);

void leverOrderTraversa(struct TreeNode *tree, QueueRef queue);

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize);

#endif /* TreeNode_h */
