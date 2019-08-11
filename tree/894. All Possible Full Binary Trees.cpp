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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return vector<TreeNode *>{};
        if(N == 1) return vector<TreeNode *>{new TreeNode(0)};
        vector<TreeNode *> result;
        for(int i = 1; i < N; i+=2){
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(N-i-1);
            for(auto l: left){
                for(auto r:right){
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 1) return {new TreeNode(0)};
        vector<TreeNode *> ans;
        for(int i = 1; i < N-1; i++){
            auto ll = allPossibleFBT(i);
            auto rr = allPossibleFBT(N-1-i);
            for(auto l: ll) for(auto r: rr){
                TreeNode *node = new TreeNode(0);
                node->left = l;
                node->right = r;
                ans.push_back(node);
            }
        }
        return ans;
    }
};