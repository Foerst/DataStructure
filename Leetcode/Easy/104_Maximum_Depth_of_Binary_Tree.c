/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int maxl = maxDepth(root->left);
    int maxr = maxDepth(root->right);
    return maxl > maxr ? maxl + 1 : maxr + 1;
}
