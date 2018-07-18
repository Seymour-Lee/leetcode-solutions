/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr) return minDepth(root->right) + 1;
        if(root->right == nullptr) return minDepth(root->left) + 1;
        return min(minDepth(root->right), minDepth(root->left)) + 1;
    }
};