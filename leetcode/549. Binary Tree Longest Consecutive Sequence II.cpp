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
        dfs(root, ans);
        return ans;
    }
    
private:
    pair<int, int> dfs(TreeNode *root, int &ans){ // {inr, dcr}
        if(root == nullptr) return {0, 0};
        int inr = 1, dcr = 1;
        if(root->left){
            auto left = dfs(root->left, ans);
            if(root->val+1 == root->left->val) inr = left.first+1;
            if(root->val-1 == root->left->val) dcr = left.second+1;
        } 
        if(root->right){
            auto right = dfs(root->right, ans);
            if(root->val-1 == root->right->val) dcr = max(dcr, right.second+1);
            if(root->val+1 == root->right->val) inr = max(inr, right.first+1);
        }
        ans = max(ans, inr + dcr - 1);
        return {inr, dcr};
    }
};