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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> p2v;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while(q.empty() == false){
            int size = q.size();
            unordered_map<int, vector<int>> x2v;
            while(size--){
                auto p = q.front(); q.pop();
                TreeNode *node = p.first;
                int x = p.second;
                x2v[x].push_back(node->val);
                if(node->left) q.push({node->left, x-1});
                if(node->right) q.push({node->right, x+1});
            }
            for(auto &p: x2v){
                sort(p.second.begin(), p.second.end());
                for(auto x: p.second) p2v[p.first].push_back(x);
            }
        }
        vector<vector<int>> ans;
        for(auto p: p2v) ans.push_back(p.second);
        return ans;
    }
};