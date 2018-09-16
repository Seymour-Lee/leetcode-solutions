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
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
    
private:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = new TreeNode(INT_MIN);
    
    void dfs(TreeNode *root){
        if(root == nullptr) return;
        dfs(root->left);
        if(first == nullptr && prev->val >= root->val)
            first = prev;
        if(first != nullptr && prev->val >= root->val)
            second = root;
        prev = root;
        dfs(root->right);
    }
};