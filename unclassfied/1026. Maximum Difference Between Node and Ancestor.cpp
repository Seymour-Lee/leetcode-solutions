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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0, INT_MAX);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int &ans, int maxval, int minval){
        if(root == nullptr) return;
        if(maxval != 0){
            ans = max(ans, abs(maxval-root->val));
        }
        if(minval != INT_MAX){
            ans = max(ans, abs(minval-root->val));
        }
        maxval = max(root->val, maxval);
        minval = min(root->val, minval);
        dfs(root->left, ans, maxval, minval);
        dfs(root->right, ans, maxval, minval);
    }
};