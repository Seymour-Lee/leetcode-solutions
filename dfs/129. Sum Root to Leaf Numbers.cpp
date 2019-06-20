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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        dfs(root, "", ans);        
        return ans;
    }
    
private:
    void dfs(TreeNode *root, string cur, int &res){
        if(root == nullptr){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            res += stoi(cur + to_string(root->val));
            return;
        }
        dfs(root->left, cur+to_string(root->val), res);
        dfs(root->right, cur+to_string(root->val), res);
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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int &ans, int cur){
        if(root == nullptr) return;
        cur = cur * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) ans += cur;
        dfs(root->left, ans, cur);
        dfs(root->right, ans, cur);
    }
};