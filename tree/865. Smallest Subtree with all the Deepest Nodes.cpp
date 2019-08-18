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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    
private:
    pair<TreeNode *, int> dfs(TreeNode *root){
        if(root == nullptr) return pair<TreeNode *, int>{nullptr, 0};
        pair<TreeNode *, int> left = dfs(root->left);
        pair<TreeNode *, int> right = dfs(root->right);
        if(left.second > right.second) 
            return pair<TreeNode *, int>{left.first, left.second+1};
        if(left.second < right.second) 
            return pair<TreeNode *, int>{right.first, right.second+1};
        return pair<TreeNode *, int>{root, right.second+1};
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    
private:
    pair<TreeNode *, int> dfs(TreeNode *root){
        if(root == nullptr) return {nullptr, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(l.second > r.second) return {l.first, l.second+1};
        if(l.second < r.second) return {r.first, r.second+1};
        return {root, l.second+1};
    }
};