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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return nullptr;
        if(inorder.size() == 1) 
            return new TreeNode(inorder[0]);
        int rval = postorder.back();
        TreeNode *root = new TreeNode(rval);
        vector<int> li;
        for(int i = 0; i < inorder.size() && inorder[i] != rval; i++)
            li.push_back(inorder[i]);
        vector<int> ri(inorder.begin()+li.size()+1,inorder.end());
        vector<int> lp(postorder.begin(), postorder.begin()+li.size());
        vector<int> rp(postorder.begin()+li.size(), postorder.end()-1);
        root->left = buildTree(li,lp);
        root->right = buildTree(ri, rp);
        return root;
    }
};