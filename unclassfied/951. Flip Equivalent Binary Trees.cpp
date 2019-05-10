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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr) return true;
        if(root1 == nullptr || root2 == nullptr) return false;
        queue<TreeNode *> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while(q1.empty() == false && q2.empty() == false){
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            if(node1 == nullptr || node2 == nullptr) return false;
            if(node1->val != node2->val) return false;
            if(node1->left && node2->left && node1->left->val == node2->left->val ||
               node1->left == nullptr && node2->left == nullptr){
                if(node1->left){
                    q1.push(node1->left);
                    q2.push(node2->left);
                }
                if(node1->right){
                    q1.push(node1->right);
                    q2.push(node2->right);
                }
            }
            else{
                if(node1->left){
                    q1.push(node1->left);
                    q2.push(node2->right);
                }
                if(node1->right){
                    q1.push(node1->right);
                    q2.push(node2->left);
                }
            }
        }
        return q1.empty() && q2.empty();
    }
};