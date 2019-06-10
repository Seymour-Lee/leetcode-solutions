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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string sstr = preorder(s, true);
        string tstr = preorder(t, true);
        return sstr.find(tstr) != string::npos;
    }

private:
    string preorder(TreeNode * root, bool left){
        if(root == nullptr){
            if(left) return "lnullptr";
            else return "rnullptr";
        }
        return "#" + to_string(root->val) + preorder(root->left, true) + preorder(root->right, false);
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string ss; dfs(s, ss);
        string tt; dfs(t, tt);
        // cout<<ss<<endl;
        // cout<<tt<<endl;
        return ss.find(tt) != string::npos;
    }
    
private:
    void dfs(TreeNode *root, string &str){
        if(root == nullptr){
            str += "nullptr,";
            return;
        }
        str += "#"+to_string(root->val) + ",";
        dfs(root->left, str);
        dfs(root->right, str);
    }
};