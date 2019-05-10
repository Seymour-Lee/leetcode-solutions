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
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return 0;
        int result = root->val;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            result = q.front()->val;
            int size = q.size();
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return result;
    }
};