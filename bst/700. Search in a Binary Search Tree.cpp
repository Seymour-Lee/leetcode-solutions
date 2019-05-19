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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)  return nullptr;
        if(root->val == val) return root;
        else if(root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;
        auto l = searchBST(root->left, val);
        if(l) return l;
        auto r = searchBST(root->right, val);
        if(r) return r;
        return nullptr;
    }
};