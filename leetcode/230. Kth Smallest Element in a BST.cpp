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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, k, arr);
        return arr.back();
    }
    
private:
    void dfs(TreeNode *node, int k, vector<int> &arr){
        if(node == nullptr) return;
        dfs(node->left, k, arr);
        if(k == arr.size()) return;
        arr.push_back(node->val);
        if(k == arr.size()) return;
        dfs(node->right, k, arr);
    }
};