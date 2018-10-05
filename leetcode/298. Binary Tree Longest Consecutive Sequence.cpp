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
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        dfs(root, ans, root->val-1, 0);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int &ans, int parent, int length){
        if(root == nullptr) return;
        length = parent+1 == root->val? length+1: 1;
        ans = max(ans, length);
        dfs(root->left, ans, root->val, length);
        dfs(root->right, ans, root->val, length);
    }
};