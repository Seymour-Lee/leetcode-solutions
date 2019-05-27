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
        if(postorder.size() == 0) return nullptr;
        int val = postorder.back();
        TreeNode *root = new TreeNode(val);
        if(postorder.size() == 1) return root;
        int pos = 0;
        while(pos < inorder.size() && inorder[pos] != val) pos++;
        auto lp = vector<int>(postorder.begin(), postorder.begin()+pos);
        auto li = vector<int>(inorder.begin(), inorder.begin()+pos);
        root->left = buildTree(li, lp);
        auto rp = vector<int>(postorder.begin()+pos, prev(postorder.end()));
        auto ri = vector<int>(inorder.begin()+pos+1, inorder.end());
        root->right = buildTree(ri, rp);
        return root;
    }
};