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
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode *root, int &ans){
        int left = root->left? dfs(root->left, ans): 0;
        int right = root->right? dfs(root->right, ans): 0;
        int value = root->val;
        ans = max(ans, max(max(left+right+value, left+value), max(right+value, value)));
        return max(max(left, right)+value, value);
    }
};

