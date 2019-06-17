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
        if(pre.size() == 0) return nullptr;
        TreeNode *node = new TreeNode(pre[0]);
        int i = 1, j = 0;
        unordered_set<int> pr, po;
        while(i < pre.size() && j < post.size()-1){
            pr.insert(pre[i++]);
            po.insert(post[j++]);
            if(pr == po) break;
        }
        int size = pr.size();
        auto lpr = vector<int>(pre.begin()+1, pre.begin()+1+size);
        auto rpr = vector<int>(pre.begin()+1+size, pre.end());
        auto lpo = vector<int>(post.begin(), post.begin()+size);
        auto rpo = vector<int>(post.begin()+size, post.end()-1);
        node->left = constructFromPrePost(lpr, lpo);
        node->right = constructFromPrePost(rpr, rpo);
        return node;
    }
};