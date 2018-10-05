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
    int largestBSTSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
private:
    struct Info{
        bool bst;
        int kids;
        int smallest;
        int largest;
        Info(bool b, int k, int s, int l): bst(b), kids(k), smallest(s), largest(l) {}
    };
    
    Info dfs(TreeNode *root, int &ans){
        if(root == nullptr) return Info(true, 0, INT_MAX, INT_MIN);
        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);
        bool bst = left.bst && right.bst;
        if(root->left) bst = bst && (left.largest < root->val);
        if(root->right) bst = bst && (root->val < right.smallest);
        if(bst == false) return Info(false, -1, INT_MAX, INT_MIN);
        ans = max(ans, left.kids+right.kids+1);
        return Info(bst, left.kids+right.kids+1, min(left.smallest, root->val), 
                    max(right.largest, root->val));
    }
};