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
        vector<double> ans;
        if(root == nullptr) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            int counter = 0;
            double sum = 0.0;
            while(size--){
                auto node = q.front(); q.pop();
                counter++;
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(sum/counter);
        }
        return ans;
    }
};