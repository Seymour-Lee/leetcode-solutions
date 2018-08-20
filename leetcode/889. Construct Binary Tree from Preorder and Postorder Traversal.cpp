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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if(n == 0) return nullptr;
        TreeNode *root = new TreeNode(pre[0]);
        if(n == 1) return root;
        int l = 0;
        for(int i = 0; i < n; i++){
            if(post[i] == pre[1]){
                l = i + 1;
                break;
            }
        }
        vector<int> ll(pre.begin()+1, pre.begin()+l+1);
        vector<int> lr(post.begin(), post.begin()+l);
        vector<int> rl(pre.begin()+l+1, pre.end());
        vector<int> rr(post.begin()+l, post.end()-1);
        root->left = constructFromPrePost(ll, lr);
        root->right = constructFromPrePost(rl, rr);
        return root;
    }
};