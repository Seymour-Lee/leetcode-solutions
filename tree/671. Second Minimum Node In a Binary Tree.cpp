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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        int result = INT_MAX;
        queue<TreeNode *>  q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur->val < result && cur->val != root->val) result = cur->val;
            if(cur->left){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return result > root->val? result == INT_MAX? -1: result: -1;
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
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return min1 == (long)INT_MAX+1? -1: min1;
    }
    
private:
    long min0 = (long)INT_MAX+1, min1 = (long)INT_MAX+1;
    
    void dfs(TreeNode *root){
        if(root == nullptr) return;
        long val = root->val;
        if(val < min0){
            min1 = min0;
            min0 = val;
        }
        else if(val < min1 && val != min0){
            min1 = val;
        }
        dfs(root->left);
        dfs(root->right);
    }
};