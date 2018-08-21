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
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == nullptr) vector<vector<string>>();
        int height = getHeight(root);
        vector<vector<string>> result(height, vector<string>((1 << height) - 1, ""));
        dfs(root, result, 0, 0, result[0].size());
        return result;
    }
    
private:
    void dfs(TreeNode *root, vector<vector<string>> & res, int level, int l, int r){
        if(root == nullptr) return;
        res[level][(l+r)/2] = to_string(root->val);
        dfs(root->left, res, level + 1, l, (l + r) / 2);
        dfs(root->right, res, level + 1, (l + r + 1) / 2, r);
    }
    
    int getHeight(TreeNode *root){
        if(root == nullptr) return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
};