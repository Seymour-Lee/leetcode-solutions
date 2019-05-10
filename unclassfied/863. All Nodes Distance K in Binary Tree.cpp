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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr || target == nullptr) return {};
        vector<int> result;
        map<TreeNode *, TreeNode *> parents;
        getParents(root, parents);
        set<TreeNode *> visited;
        dfs(target, K, result, parents, visited);
        return result;
    }
    
private:
    void getParents(TreeNode *root, map<TreeNode *, TreeNode *> &p){
        if(root == nullptr) return;
        if(root->left){
            p[root->left] = root;
            getParents(root->left, p);
        }
        if(root->right){
            p[root->right] = root;
            getParents(root->right, p);
        }
    }
    
    void dfs(TreeNode *root, int k, vector<int> &ans,
             map<TreeNode *, TreeNode *> &p, set<TreeNode *> &v){
        if(root == nullptr) return;
        if(v.find(root) != v.end()) return;
        v.insert(root);
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        dfs(root->left, k-1, ans, p, v);
        dfs(root->right, k-1, ans, p, v);
        dfs(p[root], k-1, ans, p, v);
    }
};