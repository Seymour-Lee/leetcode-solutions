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
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    pair<int, int> dfs(TreeNode *root, double &ans){
        if(root == nullptr) return {0, 0};
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        int b = l.second+r.second+root->val;
        int a = l.first+r.first+1;
        ans = max(ans, (double)b/(double)a);
        return {a, b};
    }
};
