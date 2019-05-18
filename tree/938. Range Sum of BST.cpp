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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        dfs(root, L, R, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int L, int R, int &ans){
        if(root == nullptr) return;
        if(L <= root->val && root->val <= R) ans += root->val;
        dfs(root->left, L, R, ans);
        dfs(root->right, L, R, ans);
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr) return 0;
        int ans = (L <= root->val && root->val <= R? root->val: 0);
        ans += rangeSumBST(root->left, L, R);
        ans += rangeSumBST(root->right, L, R);
        return ans;
    }
};