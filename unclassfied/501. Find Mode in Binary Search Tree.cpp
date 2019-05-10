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
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
private:
    int modecounter = 0;
    int curcounter = 0;
    int curval = INT_MIN;
    
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        dfs(root->left, ans);
        if(root->val != curval){
            curval = root->val;
            curcounter = 0;
        }
        curcounter++;
        if(curcounter > modecounter){
            ans = {};
            ans.push_back(root->val);
            modecounter = curcounter;
        }
        else if(curcounter == modecounter){
            ans.push_back(root->val);
            // modecounter++;
        }
        dfs(root->right, ans);
    }
};