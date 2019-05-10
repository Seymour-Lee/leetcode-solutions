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
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        vector<int> lefts;
        dfs(root, 1, 0, lefts, result);
        return result;
    }
    
private:
    void dfs(TreeNode *root, int pos, int depth, 
             vector<int> &lefts, int &result){
        if(root == nullptr) return;
        if(depth >= lefts.size()) lefts.push_back(pos);
        result = max(result, pos + 1 - lefts[depth]);
        dfs(root->left, pos*2, depth+1, lefts, result);
        dfs(root->right, pos*2+1, depth+1, lefts, result);
    }
};