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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        if(preorder.size() == 1) return new TreeNode(preorder[0]);
        int rval = preorder[0];
        vector<int> li;
        for(int i = 0; i < inorder.size() && inorder[i] != rval; i++)
            li.push_back(inorder[i]);
        vector<int> ri(inorder.begin()+li.size()+1, inorder.end());
        vector<int> lp(preorder.begin()+1, preorder.begin()+li.size()+1);
        vector<int> rp(preorder.begin()+li.size()+1, preorder.end());
        TreeNode *root = new TreeNode(rval);
        root->left = buildTree(lp, li);
        root->right = buildTree(rp, ri);
        return root;
    }
};