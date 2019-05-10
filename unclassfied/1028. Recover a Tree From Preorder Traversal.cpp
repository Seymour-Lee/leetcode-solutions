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
    TreeNode* recoverFromPreorder(string S) {
        return dfs(S, 0);
    }
    
private:
    TreeNode* dfs(string &S, int d){
        if(S.size() == 0) return nullptr;
        int pos = 0;
        while(pos < S.size() && S[pos] == '-') pos++;
        int depth = pos;
        if(depth != d) return nullptr;
        while(pos < S.size() && S[pos] != '-') pos++;
        string val = S.substr(depth, pos-depth);
        S = S.substr(pos);
        // cout<<d<<" "<<depth<<" "<<val<<" "<<S<<endl;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = dfs(S, d+1);
        root->right = dfs(S, d+1);
        return root;
    }
};