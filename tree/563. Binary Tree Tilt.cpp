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
    int findTilt(TreeNode* root) {
        if(root == nullptr) return 0;
        int result = 0;
        dfs(root, result);
        return result;
    }
    
private:
    int dfs(TreeNode *root, int &result){
        if(root == nullptr) return 0;
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result += left > right? left - right: right - left;
        return left + right +root->val;
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
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode *root, int &ans){
        if(root == nullptr) return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        ans += abs(l-r);
        return l+r+root->val;
    }
};