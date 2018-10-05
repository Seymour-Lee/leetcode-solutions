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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans = {root->val};
        dfs(root->left, ans, true, false);
        dfs(root->right, ans, false, true);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<int> &ans, bool lb, bool rb){
        if(root == nullptr) return;
        if(lb) ans.push_back(root->val);
        if(lb == false && rb == false && 
           root->left == nullptr && root->right == nullptr)
            ans.push_back(root->val);
        dfs(root->left, ans, lb, rb && (root->right == nullptr));
        dfs(root->right, ans, lb && (root->left == nullptr), rb);
        if(rb) ans.push_back(root->val);
    }
};