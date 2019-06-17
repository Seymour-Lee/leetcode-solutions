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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int hl = 0;
        int hr = 0;
        TreeNode *left = root;
        TreeNode *right = root;
        while(left){
            left = left->left;
            hl++;
        }
        while(right){
            right = right->right;
            hr++;
        }
        if(hl == hr) return pow(2, hl) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
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
    int countNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int &ans){
        if(root == nullptr) return;
        ans++;
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};