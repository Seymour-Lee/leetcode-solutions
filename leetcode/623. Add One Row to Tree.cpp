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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root == nullptr) return new TreeNode(v);
        if(d == 1){
            TreeNode *node = new TreeNode(v);
            node->left = root;
            return node;
        }
        root = dfs(root, true, v, d, 1);
        return root;
    }
    
private:
    TreeNode *dfs(TreeNode *root, bool left, int v, int d, int level){
        if(d == level){
            TreeNode *node = new TreeNode(v);
            if(left){
                node->left = root;
            }
            else{
                node->right = root;
            }
            return node;
        }
        if(root == nullptr) return nullptr;
        root->left = dfs(root->left, true, v, d, level+1);
        root->right = dfs(root->right, false, v, d, level+1);
        return root;
    }
};