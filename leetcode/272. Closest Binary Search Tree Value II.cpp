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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root, target, k);
        vector<int> ans;
        while(pq.empty() ==false){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
private:
    priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
    
    void dfs(TreeNode* root, double target, int k){
        if(root == nullptr) return;
        pq.push({fabs(target-root->val), root->val});
        if(pq.size() > k) pq.pop();
        dfs(root->left, target, k);
        dfs(root->right, target, k);
    }
};