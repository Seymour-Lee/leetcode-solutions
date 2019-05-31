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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
    
private:
    int mod = 1e9 + 7;
    void dfs(TreeNode *root, int &ans, int cur){
        if(root == nullptr){
            return;
        }
        cur = ((cur*2) % mod + root->val) % mod;
        if(!root->left && !root->right){
            cout<<cur<<endl;
            ans = (ans + cur) % mod;
        }
        
        dfs(root->left, ans, cur);
        dfs(root->right, ans, cur);
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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int &ans, int val){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            ans += val*2+root->val;
            return;
        }
        dfs(root->left, ans, val*2+root->val);
        dfs(root->right, ans, val*2+root->val);
    }
};