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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        dfs(root, result);
        return result;
    }
    
private:
    int dfs(TreeNode *root, bool &result){
        if(root == nullptr) return 0;
        int left = dfs(root->left, result) + 1;
        int right = dfs(root->right, result) + 1;
        if(abs(left-right) > 1) result = false;
        return max(left, right);
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
    
private:
    int dfs(TreeNode *root, bool &ans){
        if(root == nullptr) return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        if(abs(l-r) > 1) ans = false;
        return max(l, r)+1;
    }
};