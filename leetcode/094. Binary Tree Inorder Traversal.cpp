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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        dfs(root, result);
        return result;
    }
    
private:
    void dfs(TreeNode* root, vector<int> &result){
        if(root == nullptr) return;
        if(root->left) dfs(root->left, result);
        result.push_back(root->val);
        if(root->right) dfs(root->right, result);
    }
};