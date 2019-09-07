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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        if(root->val < val){
            TreeNode *ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        // val <= root->val
        if(root->right == nullptr){
            root->right = new TreeNode(val);
            return root;
        }
        
        root->right = insertIntoMaxTree(root->right, val);
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        if(root->val < val){
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};