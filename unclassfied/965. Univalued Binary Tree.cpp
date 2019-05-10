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
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root, root->val);
    }
    
    bool dfs(TreeNode *root, int val){
        if(root == nullptr) return true;
        return root->val == val && dfs(root->left, val) && dfs(root->right, val);
    }
};