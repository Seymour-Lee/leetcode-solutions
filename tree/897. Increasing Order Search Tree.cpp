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
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        return dfs(root).first;
    }
    
private:
    pair<TreeNode *, TreeNode *> dfs(TreeNode *node){
        if(node == nullptr) 
            return pair<TreeNode *, TreeNode *>{nullptr, nullptr};        
        if(node->left && node->right){
            pair<TreeNode *, TreeNode *> left = dfs(node->left);
            pair<TreeNode *, TreeNode *> right = dfs(node->right);
            left.second->right = node;
            node->right = right.first;
            node->left = nullptr;
            return pair<TreeNode *, TreeNode *>{left.first, right.second};
        }
        else if(node->left == nullptr && node->right){
            pair<TreeNode *, TreeNode *> right = dfs(node->right);
            node->right = right.first;
            return pair<TreeNode *, TreeNode *>{node, right.second};
        }
        else if(node->left && node->right == nullptr){
            pair<TreeNode *, TreeNode *> left = dfs(node->left);
            left.second->right = node;
            node->left = nullptr;
            return pair<TreeNode *, TreeNode *>{left.first, node};
        }
        else{
            return pair<TreeNode *, TreeNode *>{node, node};
        }
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
    TreeNode* increasingBST(TreeNode* root) {
        auto p = dfs(root);
        return p.first;
    }
    
private:
    pair<TreeNode *, TreeNode *> dfs(TreeNode *root){
        if(root == nullptr) return {nullptr, nullptr};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        TreeNode *head = l.first? l.first: root;
        TreeNode *tail = r.second? r.second: root;
        if(l.second) l.second->right = root;
        root->right = r.first;
        root->left = nullptr;
        return {head, tail};
    }
};