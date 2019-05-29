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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> q1;
        dfs(root1, q1);
        queue<int> q2;
        dfs(root2, q2);
        if(q1.size() != q2.size()) return false;
        while(q1.size() && q2.size()){
            if(q1.front() != q2.front()) return false;
            q1.pop();
            q2.pop();
        }
        return true;
    }
    
private:
    void dfs(TreeNode *root, queue<int> &q){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) q.push(root->val);
        if(root->left) dfs(root->left, q);
        if(root->right) dfs(root->right, q);
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
    
private:
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};