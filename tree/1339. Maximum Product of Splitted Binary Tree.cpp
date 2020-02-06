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
    int maxProduct(TreeNode* root) {
        getSum(root);
        // long long cur = 0;
        dfs(root);
        return ans % mod;
    }
    
private:
    long long ans = 0;
    int mod = 1e9+7;
    int sum = 0;
    
    void getSum(TreeNode *root){
        if(root == nullptr) return;
        sum += root->val;
        getSum(root->left);
        getSum(root->right);
    }
    
    long long dfs(TreeNode *root){
        if(root == nullptr) return 0;
        long long l = dfs(root->left);
        ans = max(ans, l*(sum-l));
        long long r = dfs(root->right);
        ans = max(ans, r*(sum-r));
        return l+r+root->val;
        // cur += root->val;
        // if(cur*(sum-cur) > ans){
        //     cout<<cur<<" "<<(sum-cur)<<endl;
        //     ans = cur*(sum-cur);
        // }
    }
};

// [1,2,3,4,5,6]
// [1,null,2,3,4,null,null,5,6]
// [2,3,9,10,7,8,6,5,4,11,1]
// [1,1]