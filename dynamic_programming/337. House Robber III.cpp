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
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
    
private:
    pair<int ,int> dfs(TreeNode *root){
        if(root == nullptr) return pair<int ,int>{0, 0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int excl = left.first + right.first;
        int incl = max(excl, left.second + right.second + root->val);
        return pair<int, int>{incl, excl};
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
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
    
private:
    pair<int, int> dfs(TreeNode *root){
        if(root == nullptr) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int ex = max(l.first, l.second) + max(r.first, r.second);
        int in = root->val + l.second + r.second;
        return {in, ex};
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
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
    
private:
    pair<int, int> dfs(TreeNode *root){
        if(root == nullptr) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int ex = max(l.first, l.second) + max(r.first, r.second);
        int in = root->val + l.second + r.second;
        return {in, ex};
    }
};