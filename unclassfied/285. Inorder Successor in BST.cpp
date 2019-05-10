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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> inorder;
        dfs(root, inorder);
        for(int i = 0; i < inorder.size()-1; i++)
            if(inorder[i] == p) return inorder[i+1];
        return nullptr;
    }
    
private:
    void dfs(TreeNode *root, vector<TreeNode*> &inorder){
        if(root == nullptr) return;
        dfs(root->left, inorder);
        inorder.push_back(root);
        dfs(root->right, inorder);
    }
};