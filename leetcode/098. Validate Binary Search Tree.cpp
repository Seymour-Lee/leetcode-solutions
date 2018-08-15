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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return root->val > getMax(root->left) &&
               root->val < getMin(root->right) &&
               isValidBST(root->left) &&
               isValidBST(root->right);
    }

private:
    long getMin(TreeNode *root){
        if(root == nullptr) return LONG_MAX;
        TreeNode *cur = root;
        while(cur->left) cur = cur->left;
        return cur->val;
    }
    
    long getMax(TreeNode *root){
        if(root == nullptr) return LONG_MIN;
        TreeNode *cur = root;
        while(cur->right) cur = cur->right;
        return cur->val;
    }
};