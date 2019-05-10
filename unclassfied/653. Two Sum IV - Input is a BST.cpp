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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        set<int> s;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            if(s.find(cur->val) == s.end()){
                s.insert(k-cur->val);
            }
            else{
                return true;
            }
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return false;
    }
};