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
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root, root->val);
    }
    
    bool dfs(TreeNode *root, int val){
        if(root == nullptr) return true;
        return root->val == val && dfs(root->left, val) && dfs(root->right, val);
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
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr) return true;
        int val = root->val;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            auto node = q.front(); q.pop();
            if(node->val != val) return false;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return true;
    }
};