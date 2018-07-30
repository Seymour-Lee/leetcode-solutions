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
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
    
private:
    int dfs(TreeNode *root, int &result){ //return the max path not including current node
        if(root == nullptr) return 0;
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        int curLeft = 0, curRight = 0;
        if(root->left && root->left->val == root->val){
            curLeft = left + 1;
        }
        if(root->right && root->right->val == root->val){
            curRight = right +1;
        }
        result = max(result, curLeft + curRight);
        return max(curLeft, curRight);
    }
};