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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        if(root->left) dfs(root->left, ans);
        if(root->right) dfs(root->right, ans);
        ans.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode *> stk;
        stk.push(root);
        while(stk.empty() == false){
            TreeNode *node = stk.top(); stk.pop();
            if(node->left == nullptr && node->right == nullptr){
                ans.push_back(node->val);
            }
            else{
                stk.push(node);
                if(node->right) stk.push(node->right);
                if(node->left) stk.push(node->left);
                node->left = nullptr;
                node->right = nullptr;
            }
        }
        return ans;
    }
};
