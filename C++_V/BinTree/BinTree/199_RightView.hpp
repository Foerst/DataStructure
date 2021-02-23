//
//  199_RightView.hpp
//  BinTree
//
//  Created by edy on 2021/2/23.
//

#ifndef _99_RightView_hpp
#define _99_RightView_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <vector>
#include <queue>

using namespace std;

class RightView {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();
            for (int i=0; i<size; i++) {
                TreeNode *top = queue.front();
                queue.pop();
                if (top->left) {
                    queue.push(top->left);
                }
                if (top->right) {
                    queue.push(top->right);
                }
                if (i==size-1) {
                    ret.push_back(top->val);
                }
            }
        }
        return ret;
    }
};
#endif /* _99_RightView_hpp */
