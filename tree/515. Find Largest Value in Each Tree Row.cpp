/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const auto ______ = [](){ 
        std::cout.sync_with_stdio(false);
        cin.tie(0);
        return 0;
}();

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        vector<int> result;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            int largest = INT_MIN;
            while(size--){
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                largest = max(largest, node->val);
            }
            result.push_back(largest);
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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            int maxval = q.front()->val;
            while(size--){
                auto node = q.front(); q.pop();
                maxval = max(maxval, node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};