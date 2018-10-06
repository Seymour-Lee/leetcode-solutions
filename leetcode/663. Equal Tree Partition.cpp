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
    bool checkEqualTree(TreeNode* root) {
        stack<int> sums;
        int sum = dfs(root, sums);
        sums.pop();
        if(sum % 2 == 0){
            while(sums.empty() == false){
                auto top = sums.top(); sums.pop();
                if(top == sum/2) return true;
            }
        }
        return false;
    }
    
private:
    int dfs(TreeNode *root, stack<int> &sums){
        if(root == nullptr) return 0;
        sums.push(dfs(root->left, sums) + dfs(root->right, sums) + root->val);
        return sums.top();
    }
};