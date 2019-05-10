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
    int findClosestLeaf(TreeNode* root, int k) {
        map<int, vector<TreeNode *>> g;
        dfs(root, g);
        if(g[k] == vector<TreeNode *>()) return k;
        set<int> seen;
        queue<int> q;
        q.push(k);
        seen.insert(k);
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto nodes = g[q.front()]; q.pop();
                for(auto node: nodes){
                    if(node->left == nullptr && node->right == nullptr) return node->val;
                    if(seen.find(node->val) == seen.end()){
                        q.push(node->val);
                        seen.insert(node->val);
                    }
                }
            }
        }
        return -1;
    }
    
private:
    void dfs(TreeNode *root, map<int, vector<TreeNode *>> &g){
        if(root == nullptr) return;
        if(root->left){
            g[root->val].push_back(root->left);
            g[root->left->val].push_back(root);
            dfs(root->left, g);
        }
        if(root->right){
            g[root->val].push_back(root->right);
            g[root->right->val].push_back(root);
            dfs(root->right, g);
        }
        if(root->left == nullptr && root->right == nullptr) 
            g[root->val] = vector<TreeNode *>();
    }
};