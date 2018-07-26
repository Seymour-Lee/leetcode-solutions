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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        int result = INT_MAX;
        queue<TreeNode *>  q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur->val < result && cur->val != root->val) result = cur->val;
            if(cur->left){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return result > root->val? result == INT_MAX? -1: result: -1;
    }
};