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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return root;
        if(root->left) root->left = pruneTree(root->left);
        if(root->right) root->right = pruneTree(root->right);
        if(root->left == nullptr && root->right == nullptr && root->val == 0){
            delete root;
            return nullptr;
        }
        return root;
    }
};

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
    TreeNode* pruneTree(TreeNode* root) {
        int l = dfs(root);
        return l? root: nullptr;
    }
    
private:
    int dfs(TreeNode *root){
        if(root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int ans = l + r + root->val;
        if(l == 0) root->left = nullptr;
        if(r == 0) root->right = nullptr;
        return ans;
    }
};