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
        dfs(root, ans);
        return ans;
    }
    
private:
    // return {minval, maxval}
    pair<int, int> dfs(TreeNode *root, int &ans){
        if(root == nullptr) return {1, -1};
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        int minval = min(l.first <= l.second? l.first: INT_MAX,
                         r.first <= r.second? r.first: INT_MAX);
        int maxval = max(l.first <= l.second? l.second: INT_MIN,
                         r.first <= r.second? r.second: INT_MIN);
        if(minval != INT_MAX) ans = max(ans, abs(root->val-minval));
        if(maxval != INT_MIN) ans = max(ans, abs(root->val-maxval));
        return {min(root->val, minval), max(root->val, maxval)};
    }
};