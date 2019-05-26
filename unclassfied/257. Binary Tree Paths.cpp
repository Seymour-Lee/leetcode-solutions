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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == nullptr) return result;
        dfs(root, result, "");
        return result;
    }
private:
    void dfs(TreeNode *root, vector<string> &result, string str){
        stringstream stream;
        stream<<root->val;
        string num;
        stream>>num;
        str = str + "->" + num;
        if(root->left == nullptr && root->right == nullptr) result.push_back(str.substr(2, str.size()-2));
        if(root->left) dfs(root->left, result, str);
        if(root->right) dfs(root->right, result, str);
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, ans, "");
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<string> &ans, string cur){
        if(root == nullptr) return;
        cur += to_string(root->val) + "->";
        if(root->left == nullptr && root->right == nullptr) ans.push_back(cur.substr(0, cur.size()-2));
        dfs(root->left, ans, cur);
        dfs(root->right, ans, cur);
    }
};