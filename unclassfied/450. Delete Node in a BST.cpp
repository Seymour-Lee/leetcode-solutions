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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        TreeNode *result = nullptr;
        if(root->left == nullptr){
            result = root->right;
        }
        else if(root->right == nullptr){
            result = root->left;
        }
        else{
            result = root->right;
            TreeNode *leftest = root->right;
            while(leftest->left) leftest = leftest->left;
            leftest->left = root->left;
        }
        delete root;
        return result;
    }
};