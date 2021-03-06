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
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    bool dfs(TreeNode *root, int &ans){
        if(root == nullptr) return true;
        bool left = dfs(root->left, ans);
        bool right = dfs(root->right, ans);
        if(left == false || right == false) return false;
        bool res = (root->left? root->val == root->left->val: true) &&
            (root->right? root->val == root->right->val: true); 
        if(res) ans++;
        return res;
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
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    unordered_set<int> dfs(TreeNode *root, int &ans){
        if(root == nullptr) return {};
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        for(auto e: l) r.insert(e);
        r.insert(root->val);
        if(r.size() == 1) ans++;
        return r;
    }
};