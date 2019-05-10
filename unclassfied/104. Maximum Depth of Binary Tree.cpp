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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        if(root->left && root->right) return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        else if(root->left) return maxDepth(root->left) + 1;
        else return maxDepth(root->right) + 1;
        
    }
};