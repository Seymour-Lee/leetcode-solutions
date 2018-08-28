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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            vector<int> cur = {};
            stack<int> stk;
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                if(level % 2 == 0) cur.push_back(node->val);
                else stk.push(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            while(level % 2 == 1 && stk.empty() == false){
                cur.push_back(stk.top());
                stk.pop();
            }
            level++;
            result.push_back(cur);
        }
        return result;
    }
};