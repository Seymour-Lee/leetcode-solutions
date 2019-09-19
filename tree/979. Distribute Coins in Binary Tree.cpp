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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode *root, int &ans){
        if(root == nullptr) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans += abs(left) + abs(right);
        return root->val + left + right - 1;
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
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode *root, int &ans){
        if(root == nullptr) return 0;
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val+l+r-1;
    }
};