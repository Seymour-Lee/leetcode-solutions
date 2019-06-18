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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == nullptr) return {};
        map<TreeNode *, int> ptr2lvl;
        int maxlvl = INT_MIN;
        dfs(root, ptr2lvl, maxlvl);
        vector<vector<int>> ans(maxlvl+1);
        for(auto it: ptr2lvl){
            ans[it.second].push_back(it.first->val);
        } 
        return ans;
    }
    
private:
    int dfs(TreeNode *root, map<TreeNode *, int> &ptr2lvl, int &maxlvl){
        if(root == nullptr) return -1;
        int level = max(dfs(root->left, ptr2lvl, maxlvl), 
                        dfs(root->right, ptr2lvl, maxlvl))+1;
        ptr2lvl[root] = level;
        maxlvl = max(maxlvl, level);
        return level;
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(root == nullptr) return {};
        unordered_map<TreeNode *, int> n2d;
        int maxdep = INT_MIN;
        dfs(root, n2d, maxdep);
        vector<vector<int>> ans(maxdep+1, vector<int>{});
        for(auto p: n2d) ans[p.second].push_back(p.first->val);
        return ans;
    }
    
private:
    int dfs(TreeNode *root, unordered_map<TreeNode *, int> &n2d, int &maxval){
        if(root == nullptr) return 0;
        int l = dfs(root->left, n2d, maxval);
        int r = dfs(root->right, n2d, maxval);
        n2d[root] = max(l, r);
        maxval = max({l, r, maxval});
        return max(l, r) + 1;
    }
};