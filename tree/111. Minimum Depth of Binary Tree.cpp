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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr) return minDepth(root->right) + 1;
        if(root->right == nullptr) return minDepth(root->left) + 1;
        return min(minDepth(root->right), minDepth(root->left)) + 1;
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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MAX;
        dfs(root, 1, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int level, int &ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) ans = min(ans, level);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
};