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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->right == nullptr) return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = nullptr;
        root->right = nullptr;
        TreeNode *ans = dfs(left, root, right);
        return ans;
    }
    
private:
    TreeNode *dfs(TreeNode *root, TreeNode *parent, TreeNode *sibling){
        if(root == nullptr) return nullptr;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = sibling;
        root->right = parent;
        if(left) return dfs(left, root, right);
        return root;
    }
};