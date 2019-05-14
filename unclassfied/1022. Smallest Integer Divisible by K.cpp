class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0) return -1;
        if(K % 5 == 0) return -1;
        
        if(K == 1) return 1;
        int r = 1, p = 1;
        for(int i = 2; ; i++){
            p = ((p%K)*(10%K))%K;
            r = (r%K + p%K) % K;
            if(r == 0) return i;
        }
        return -1;
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
    void dfs(TreeNode *root, int &ans, int cur){
        if(root == nullptr) return;
        cur = cur*2 + root->val;
        if(root->left == nullptr && root->right == nullptr) ans += cur;
        dfs(root->left, ans, cur);
        dfs(root->right, ans, cur);
    }
};