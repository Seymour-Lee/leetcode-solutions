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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int result = 0;
        queue<pair<TreeNode *, bool>> q;
        q.push(pair<TreeNode *, bool>(root, false));
        while(!q.empty()){
            TreeNode *node = q.front().first;
            bool isLeft = q.front().second;
            q.pop();
            if(node->left) q.push(pair<TreeNode *, bool>(node->left, true));
            if(node->right) q.push(pair<TreeNode *, bool>(node->right, false));
            if(node->left == nullptr && node->right == nullptr && isLeft){
                result += node->val;
            } 
        }
        return result;
    }
};