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
        int val = preorder[0];
        TreeNode *root = new TreeNode(val);
        if(preorder.size() == 1) return root;
        int pos = 0;
        while(pos < inorder.size() && inorder[pos] != val) pos++;
        auto lp = vector<int>(preorder.begin()+1, preorder.begin()+pos+1);
        auto li = vector<int>(inorder.begin(), inorder.begin()+pos);
        root->left = buildTree(lp, li);
        auto rp = vector<int>(preorder.begin()+pos+1, preorder.end());
        auto ri = vector<int>(inorder.begin()+pos+1, inorder.end());
        root->right = buildTree(rp, ri);
        return root;
    }
};