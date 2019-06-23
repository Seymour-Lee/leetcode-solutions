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
    int pathSum(TreeNode* root, int sum) {
        return root? dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum): 0;
    }
    
private:
    int dfs(TreeNode *root, int sum){
        return root? (root->val == sum) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val): 0;
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
    int pathSum(TreeNode* root, int sum) {
        return root? dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum): 0;
    }
    
private:
    int dfs(TreeNode *root, int sum){
        return root? (root->val == sum) + dfs(root->left, sum-root->val) + dfs(root->right, sum-root->val): 0;
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
    int pathSum(TreeNode* root, int sum) {
        return root? dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum): 0;
    }
    
private:
    int dfs(TreeNode *root, int sum){
        return root? (root->val == sum) + dfs(root->left, sum-root->val) + dfs(root->right, sum-root->val): 0;
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
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        dfs(root, sum, {0}, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int target, vector<int> sums, int &ans){
        if(root == nullptr) return;
        sums.push_back(sums.back()+root->val);
        for(int i = 0; i < sums.size()-1; i++) if(sums.back()-sums[i] == target) ans++;
        dfs(root->left, target, sums, ans);
        dfs(root->right, target, sums, ans);
    }
};