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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        vector<int> ans;
        int i = 0;
        return dfs(root, i, v, ans)? ans: vector<int>{-1};
    }
    
private:
    bool dfs(TreeNode *root, int &i, vector<int> &v, vector<int> &ans){
        if(root == nullptr) return true;
        if(root->val != v[i++]) return false;
        if(root->left && root->left->val != v[i]){
            ans.push_back(root->val);
            return dfs(root->right, i, v, ans) && dfs(root->left, i, v, ans);
        }
        else return dfs(root->left, i, v, ans) && dfs(root->right, i, v, ans);
    }
};