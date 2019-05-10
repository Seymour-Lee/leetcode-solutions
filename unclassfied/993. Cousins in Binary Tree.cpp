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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> xx, yy;
        dfs(root, -1, 0, x, xx);
        dfs(root, -1, 0, y, yy);
        return (xx.first != yy.first && xx.second == yy.second);
    }
    
private:
    void dfs(TreeNode *root, int p, int d, int value, pair<int, int> &ans){ // parent, d
        if(root == nullptr) return ;
        if(root->val == value) ans = {p, d};
        dfs(root->left, root->val, d+1, value, ans);
        dfs(root->right, root->val, d+1, value, ans);
    }
};