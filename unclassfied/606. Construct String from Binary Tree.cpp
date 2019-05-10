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
    string tree2str(TreeNode* t) {
        if(t == nullptr) return "";
        stringstream stream;
        stream<<t->val;
        string result;
        stream>>result;
        if(t->left == nullptr && t->right == nullptr) return result;
        result += "(";
        result += tree2str(t->left) + ")";
        if(t->right) result += "(" + tree2str(t->right) + ")";
        return result;
    }
private:

};