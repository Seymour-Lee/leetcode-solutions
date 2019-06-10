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
    int minDiffInBST(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        int result = INT_MAX;
        queue<TreeNode *> q;
        q.push(root);
        vector<int> values;
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            values.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        sort(values.begin(), values.end());
        for(int i = 1; i < values.size(); i++){
            result = min(result, values[i]-values[i-1]);
        }
        return result;
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
    int minDiffInBST(TreeNode* root) {
        long ans = INT_MAX;
        long prev = INT_MIN;
        dfs(root, ans, prev);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, long &ans, long &prev){
        if(root == nullptr) return;
        dfs(root->left, ans, prev);
        ans = min(ans, root->val-prev);
        prev = root->val;
        dfs(root->right, ans, prev);
    }
};