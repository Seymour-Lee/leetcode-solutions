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
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            bool full = true;
            while(size--){
                auto node = q.front(); q.pop();
                if(node == nullptr) break;
                if(node->left == nullptr || node->right == nullptr) full = false;
                q.push(node->left);
                q.push(node->right);
                
            }
            if(full == false) {
                while(q.empty() == false && q.front() != nullptr){
                    auto node = q.front(); q.pop();
                    if(node->left || node->right) return false;
                }
                break;
            }
        }
        while(q.empty() == false){
            if(q.front() != nullptr){
                return false;
            }
            q.pop();
        }
        return true;
    }
};