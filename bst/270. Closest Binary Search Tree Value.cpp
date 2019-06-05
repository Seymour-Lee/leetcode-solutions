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
    int closestValue(TreeNode* root, double target) {
        double ans = (double)root->val;
        dfs(root, target, ans);
        return (int)ans;
    }
    
private:
    void dfs(TreeNode *root, double target, double &ans){
        if(root == nullptr) return;
        if(abs((double)root->val-target)<abs(target-ans)) ans = (double)root->val;
        if((double)root->val > target) dfs(root->left, target, ans);
        else if((double)root->val < target) dfs(root->right, target, ans);
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
    int closestValue(TreeNode* root, double target) {
        double ans = (double)root->val;
        dfs(root, target, ans);
        return (int)ans;
    }
    
private:
    void dfs(TreeNode *root, double target, double &ans){
        if(root == nullptr) return;
        if(abs((double)root->val-target)<abs(target-ans)) ans = (double)root->val;
        if((double)root->val > target) dfs(root->left, target, ans);
        else if((double)root->val < target) dfs(root->right, target, ans);
    }
};