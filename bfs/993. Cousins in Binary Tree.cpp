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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> xx, yy;
        dfs(root, -1, 0, x, xx);
        dfs(root, -1, 0, y, yy);
        return (xx.first != yy.first && xx.second == yy.second);
    }
    
private:
    void dfs(TreeNode *root, int p, int d, int value, pair<int, int> &ans){ // parent, d
        if(root == nullptr) return ;
        if(root->val == value) ans = {p, d};
        dfs(root->left, root->val, d+1, value, ans);
        dfs(root->right, root->val, d+1, value, ans);
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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr) return false;
        queue<TreeNode *> q;
        q.push(root);
        int xl = -1, yl = -1;
        TreeNode *xp = nullptr, *yp = nullptr;
        int level = 0;
        while(q.empty() == false){
            if(xp && yp) break;
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                if(node->left){
                    if(node->left->val == x) xl = level, xp = node;
                    if(node->left->val == y) yl = level, yp = node;
                    q.push(node->left);
                }
                if(node->right){
                    if(node->right->val == x) xl = level, xp = node;
                    if(node->right->val == y) yl = level, yp = node;
                    q.push(node->right);
                }
            }
            level++;
        }
        return xl == yl && xp != yp;
    }
};