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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        find(root, x);
        int l = 0, r = 0;
        count(node->left, l);
        count(node->right, r);
        cout<<l<<" "<<r<<" "<<n/2<<endl;
        return l > n/2 || r > n/2 || l+r+1 <= n/2;
    }
    
private:
    TreeNode *node = nullptr;
    void find(TreeNode *root, int x){
        if(root == nullptr) return;
        if(node != nullptr) return;
        if(root->val == x) node = root;
        find(root->left, x);
        find(root->right, x);
    }
    
    void count(TreeNode *root, int &counter){
        if(root == nullptr) return;
        counter++;
        count(root->left, counter);
        count(root->right, counter);
    }
};