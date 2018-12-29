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
    int minCameraCover(TreeNode* root) {
        auto vec = dfs(root);
        return min(vec[0], vec[1]);
    }
    
private:
    vector<int> dfs(TreeNode *root){ 
        if(root == nullptr) return {0, 0, 0}; // me, one kid, not cover
        if(root->left && root->right){
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            int self = 1 + *min_element(l.begin(), l.end()) + *min_element(r.begin(), r.end());
            int kid = min(l[0] + min(r[0], r[1]), r[0] + min(l[0], l[1]));
            int no = l[1] + r[1];
            return {self, kid, no};
        }
        else if(root->left){
            auto l = dfs(root->left);
            int self = 1 + *min_element(l.begin(), l.end());
            int kid = l[0];
            int no = l[1];
            return {self, kid, no};
        }
        else if(root->right){
            auto r = dfs(root->right);
            int self = 1 + *min_element(r.begin(), r.end());
            int kid = r[0];
            int no = r[1];
            return {self, kid, no};
        }
        else{
            return {1, INT_MAX/2, 0};
        }
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
    int minCameraCover(TreeNode* root) {
        auto vec = dfs(root);
        return min(vec[0], vec[1]);
    }
    
private:
    vector<int> dfs(TreeNode *root){ 
        if(root == nullptr) return {0, 0, 0}; // me, one kid, not cover
        if(root->left && root->right){
            auto l = dfs(root->left);
            auto r = dfs(root->right);
            int self = 1 + *min_element(l.begin(), l.end()) + *min_element(r.begin(), r.end());
            int kid = min(l[0] + min(r[0], r[1]), r[0] + min(l[0], l[1]));
            int no = l[1] + r[1];
            return {self, kid, no};
        }
        else if(root->left || root->right){
            auto c = dfs(root->left? root->left: root->right);
            int self = 1 + *min_element(c.begin(), c.end());
            int kid = c[0];
            int no = c[1];
            return {self, kid, no};
        }
        else{
            return {1, INT_MAX/2, 0};
        }
    }
};