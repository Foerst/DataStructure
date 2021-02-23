//
//  main.cpp
//  BinTree
//
//  Created by edy on 2021/2/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Command {
public:
    string s;//print, go
    TreeNode *node;
    Command(string s, TreeNode *node): s(s), node(node){}
};

 
class Solution {
public:
    vector<int> inorderTraversalNonRec(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<Command> stack;
        stack.push(Command("go", root));
        while (!stack.empty()) {
            Command cmd = stack.top();
            stack.pop();
            if (cmd.s == "print") {
                ret.push_back(cmd.node->val);
            } else {
                if (cmd.node->right) {
                    stack.push(Command("go", cmd.node->right));
                }
                stack.push(Command("print", cmd.node));
                if (cmd.node->left) {
                    stack.push(Command("go", cmd.node->left));
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
