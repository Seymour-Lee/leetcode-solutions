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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root);
    }

private:
    pair<TreeNode *, TreeNode *> dfs(TreeNode *root){
        if(root == nullptr) 
            return pair<TreeNode *, TreeNode *>{nullptr, nullptr};
        pair<TreeNode *, TreeNode *> left = dfs(root->left);
        pair<TreeNode *, TreeNode *> right = dfs(root->right);
        TreeNode *tail = root;
        if(left.first != nullptr){
            tail->right = left.first;
            tail = left.second;
        }
        if(right.first != nullptr){
            tail->right = right.first;
            tail = right.second;
        }
        root->left = nullptr;
        return pair<TreeNode *, TreeNode *>{root, tail};
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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    
private:
    pair<TreeNode *, TreeNode *> dfs(TreeNode *root){
        if(root == nullptr) return {nullptr, nullptr};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        root->left = nullptr;
        TreeNode *tail = root;
        if(l.first) tail->right = l.first, tail = l.second;
        if(r.first) tail->right = r.first, tail = r.second;
        return {root, tail};
    }
};