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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        dfs(root);
        int most = 0;
        for(auto e: table) most = max(most, e.second);
        for(auto e: table) if(e.second == most) result.push_back(e.first);
        return result;
    }
    
private:
    map<int, int> table;
    
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int l = root->left? dfs(root->left): 0;
        int r = root->right? dfs(root->right): 0;
        table[root->val + l + r]++;
        return root->val + l + r;
    }
};