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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        dfs(root, vector<int>{}, sum, 0, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<int> vec, int target, int sum, vector<vector<int>> &ans){
        if(root == nullptr) return;
        sum += root->val;
        vec.push_back(root->val);
        if(sum == target && root->left == nullptr && root->right == nullptr){
            ans.push_back(vec);
        }
        dfs(root->left, vec, target, sum, ans);
        dfs(root->right, vec, target, sum, ans);
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        dfs(root, sum, ans, {});
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int sum, vector<vector<int>> &ans, vector<int> cur){
        if(root == nullptr) return;
        cur.push_back(root->val);
        if(root->val == sum && root->left == nullptr && root->right == nullptr){
            ans.push_back(cur);
            return;
        }
        dfs(root->left, sum-root->val, ans, cur);
        dfs(root->right, sum-root->val, ans, cur);
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        dfs(root, ans, {}, sum);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<vector<int>> &ans, vector<int> cur, int sum){
        if(root == nullptr) return;
        sum -= root->val;
        cur.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && sum == 0) ans.push_back(cur);
        if(root->left) dfs(root->left, ans, cur, sum);
        if(root->right) dfs(root->right, ans, cur, sum);
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(root, ans, cur, sum);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<vector<int>> &ans, vector<int> &cur, int sum){
        if(root == nullptr) return;
        sum -= root->val;
        cur.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && sum == 0) ans.push_back(cur);
        if(root->left) dfs(root->left, ans, cur, sum);
        if(root->right) dfs(root->right, ans, cur, sum);
        cur.pop_back();
    }
};