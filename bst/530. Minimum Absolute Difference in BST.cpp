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
    int getMinimumDifference(TreeNode* root) {
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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        dfs(root, ans);
        return ans;
    }
    
private:
    pair<int, int> dfs(TreeNode *root, int &ans){
        if(root == nullptr) return {-1, -1};
        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);
        int minval = (l.first == -1? root->val: l.first);
        int maxval = (r.second == -1? root->val: r.second);
        if(l.first != -1) ans = min(ans, abs(root->val-l.second));
        if(r.first != -1) ans = min(ans, abs(root->val-r.first));
        return {minval, maxval};
    }
};