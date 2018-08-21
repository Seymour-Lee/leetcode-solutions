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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        dfs(result, root);
        return result;
    }
    
private:
    void dfs(vector<int> &res, TreeNode *node){
        if(node == nullptr) return;
        res.push_back(node->val);
        dfs(res, node->left);
        dfs(res, node->right);
    }
};