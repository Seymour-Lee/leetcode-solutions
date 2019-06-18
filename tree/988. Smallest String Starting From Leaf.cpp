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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, ans, "");
        return ans;
    }
    
private:
    void dfs(TreeNode *root, string &ans, string str){
        if(root == nullptr) return;
        str = string(1, root->val+'a') + str;
        if(root->left == nullptr && root->right == nullptr) ans = ans.empty()? str: min(ans, str);
        dfs(root->left, ans, str);
        dfs(root->right, ans, str);
    }
};