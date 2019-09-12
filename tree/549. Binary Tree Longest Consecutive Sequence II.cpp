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
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    pair<int, int> dfs(TreeNode *root, int &ans){
        if(root == nullptr) return {0, 0};
        int inc = 1, dec = 1;
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        if(root->left){
            if(root->val+1 == root->left->val) inc = l.first+1;
            if(root->val-1 == root->left->val) dec = l.second+1;
        }
        if(root->right){
            if(root->val+1 == root->right->val) inc = max(inc, r.first+1);
            if(root->val-1 == root->right->val) dec = max(dec, r.second+1);
        }
        ans = max(ans, inc+dec-1);
        return {inc, dec};
    }
};