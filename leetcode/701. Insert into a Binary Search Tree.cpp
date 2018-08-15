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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }
        dfs(root, val);
        return root;
    }
    
private:
    void dfs(TreeNode *root, int val){
        if(root == nullptr) return;
        if(root->val > val){
            if(root->left == nullptr){
                root->left = new TreeNode(val);
                return;
            }
            dfs(root->left, val);
        }
        else{
            if(root->right == nullptr){
                root->right = new TreeNode(val);
                return;
            }
            dfs(root->right, val);
        }
    }
};