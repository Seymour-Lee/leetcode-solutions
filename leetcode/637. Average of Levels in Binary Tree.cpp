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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == nullptr) return result;
        queue<TreeNode *> q;
        q.push(root);
        int size;
        double sum;
        while(!q.empty()){
            size = q.size();
            sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode *cur = q.front();
                q.pop();
                sum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            result.push_back(sum / size);
        }
        return result;
    }
};