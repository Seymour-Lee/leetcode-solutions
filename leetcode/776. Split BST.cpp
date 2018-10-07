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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(root == nullptr) return {nullptr, nullptr};
        if(root->val <= V){
            auto ans = splitBST(root->right, V);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        }
        else{
            auto ans = splitBST(root->left, V);
            root->left = ans[1];
            ans[1] = root;
            return ans;
        }
    }
};