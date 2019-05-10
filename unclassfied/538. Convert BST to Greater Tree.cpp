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
    static bool cmp(const TreeNode *a, const TreeNode *b){
        return a->val > b->val;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        vector<TreeNode *> nodes;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            nodes.push_back(node);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        sort(nodes.begin(), nodes.end(), cmp);
        int sum = 0;
        for(auto node: nodes){
            int cur = node->val;
            node->val += sum;
            sum += cur;
        }
        return root;
    }
};