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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;
        map<int, int> numToTimes;
        dfs(root, numToTimes);
        int most = 0;
        for(auto item: numToTimes) most = max(most, item.second);
        for(auto item: numToTimes){
            if(item.second == most) result.push_back(item.first);
        }
        return result;
    }
    
private:
    void dfs(TreeNode *root, map<int, int> &table){
        if(root == nullptr) return;
        table[root->val]++;
        dfs(root->left, table);
        dfs(root->right, table);
    }
};