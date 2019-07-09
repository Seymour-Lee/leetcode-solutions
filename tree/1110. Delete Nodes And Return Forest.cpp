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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> d(to_delete.begin(), to_delete.end());
        unordered_set<TreeNode *> ans;
        if(root) ans.insert(root);
        dfs(root, ans, d);
        return vector<TreeNode *>(ans.begin(), ans.end());
    }
    
private:
    TreeNode* dfs(TreeNode *root, unordered_set<TreeNode *> &ans, unordered_set<int> &d){
        if(root == nullptr) return nullptr;
        if(d.find(root->val) != d.end()){
            d.erase(root->val);
            if(ans.find(root) != ans.end()) ans.erase(root);
            if(root->left) ans.insert(root->left);
            if(root->right) ans.insert(root->right);
            dfs(root->left, ans, d);
            dfs(root->right, ans, d);
            return nullptr;
        }
        else{
            root->left = dfs(root->left, ans, d);
            root->right = dfs(root->right, ans, d);
        }
        return root;
    }
};