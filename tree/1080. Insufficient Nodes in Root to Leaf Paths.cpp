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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit, 0).first;
    }
    
private:
    pair<TreeNode*, int> dfs(TreeNode *root, int limit, int sum){
        if(root == nullptr) return {nullptr, sum};
        auto l = dfs(root->left, limit, sum+root->val);
        auto r = dfs(root->right, limit, sum+root->val);
        int lmax = l.second;
        int rmax = r.second;
        if(lmax < limit) root->left = nullptr;
        if(rmax < limit) root->right = nullptr;
        int maxval = max(lmax, rmax);
        if(maxval < limit) return {nullptr, maxval};
        return {root, maxval};
    }
};