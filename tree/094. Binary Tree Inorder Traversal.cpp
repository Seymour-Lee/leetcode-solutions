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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        dfs(root, result);
        return result;
    }
    
private:
    void dfs(TreeNode* root, vector<int> &result){
        if(root == nullptr) return;
        if(root->left) dfs(root->left, result);
        result.push_back(root->val);
        if(root->right) dfs(root->right, result);
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while(node != nullptr || stk.empty() == false){
            while(node != nullptr){
                stk.push(node);
                node = node->left;
            }
            node = stk.top(); stk.pop();
            ans.push_back(node->val);
            node = node->right;
        }
        return ans;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
};