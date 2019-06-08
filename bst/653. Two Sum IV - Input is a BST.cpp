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
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        set<int> s;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            if(s.find(cur->val) == s.end()){
                s.insert(k-cur->val);
            }
            else{
                return true;
            }
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return false;
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> l;
        dfs(root, l);
        int i = 0, j = l.size()-1;
        while(i < j){
            if(l[i]+l[j] == k) return true;
            if(l[i]+l[j] < k) i++;
            else j--;
        }
        return false;
    }
    
private:
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == nullptr) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
};