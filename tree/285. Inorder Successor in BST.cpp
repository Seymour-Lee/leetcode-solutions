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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> inorder;
        dfs(root, inorder);
        for(int i = 0; i < inorder.size()-1; i++)
            if(inorder[i] == p) return inorder[i+1];
        return nullptr;
    }
    
private:
    void dfs(TreeNode *root, vector<TreeNode*> &inorder){
        if(root == nullptr) return;
        dfs(root->left, inorder);
        inorder.push_back(root);
        dfs(root->right, inorder);
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return ans;
    }
    
private:
    TreeNode *prev = nullptr;
    TreeNode *ans = nullptr;
    void dfs(TreeNode* root, TreeNode* p){
        if(root == nullptr) return;
        dfs(root->left, p);
        if(prev == p) ans = root;
        prev = root;
        dfs(root->right, p);
    }
};