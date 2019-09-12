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
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        vector<int> lefts;
        dfs(root, 1, 0, lefts, result);
        return result;
    }
    
private:
    void dfs(TreeNode *root, int pos, int depth, 
             vector<int> &lefts, int &result){
        if(root == nullptr) return;
        if(depth >= lefts.size()) lefts.push_back(pos);
        result = max(result, pos + 1 - lefts[depth]);
        dfs(root->left, pos*2, depth+1, lefts, result);
        dfs(root->right, pos*2+1, depth+1, lefts, result);
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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while(q.empty() == false){
            int size = q.size();
            int l = -1, r = -1;
            while(size--){
                auto p = q.front(); q.pop();
                TreeNode *node = p.first;
                if(l == -1) l = p.second;
                r = p.second - l;
                if(node->left) q.push({node->left, r*2});
                if(node->right) q.push({node->right, r*2+1});
            }
            ans = max(ans, r+1);
        }
        return ans;
    }
};

