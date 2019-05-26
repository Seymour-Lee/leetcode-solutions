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
    TreeNode* bstToGst(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return root;
    }
    
private:
    void dfs(TreeNode *root, int &ans){
        if(root == nullptr) return;
        dfs(root->right, ans);
        ans += root->val;
        // cout<<ans<<endl;
        root->val = ans;
        dfs(root->left, ans);
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
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        dfs(root, val);
        return root;
    }
    
private:
    void dfs(TreeNode *root, int &val){
        if(root == nullptr) return;
        dfs(root->right, val);
        val += root->val;
        root->val = val;
        dfs(root->left, val);
    }
};