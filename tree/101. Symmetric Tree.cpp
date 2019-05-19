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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        
        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode *left, TreeNode *right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;
        
        if(left->val != right->val) return false;
        
        if(left->left && !left->right && !right->left && right->right){
            return compare(left->left, right->right);
        }
        else if(!left->left && left->right && right->left && !right->right){
            return compare(left->right, right->left);
        }
        else if(left->left && left->right && right->left && right->right){
            return compare(left->left, right->right) && compare(left->right, right->left);
        }
        else if(!left->left && !left->right && !right->left && !right->right){
            return true;
        }
        else{
            return false;
        }
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root->left, root->right);
    }
    
private:
    bool dfs(TreeNode *l, TreeNode *r){
        if(l == nullptr && r == nullptr) return true;
        if(!(l && r)) return false;
        if(l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
};