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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 1;
        int maxval = 0;
        queue<TreeNode *> q;
        int level = 1;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            int val = 0;
            while(size--){
                auto node = q.front(); q.pop();
                val += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(val > maxval){
                ans = level;
                maxval = val;
            }
            level++;
        }
        return ans;
    }
};