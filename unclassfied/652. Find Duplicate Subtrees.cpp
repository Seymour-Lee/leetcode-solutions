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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == nullptr) return vector<TreeNode *>();
        map<string, int> sub2freq;
        vector<TreeNode *> result;
        tree2str(root, sub2freq, result);
        return result;
    }
    
private:
    string tree2str(TreeNode *root, map<string, int> &curred, 
                    vector<TreeNode *> &res){
        if(root == nullptr) return "";
        string lstr = tree2str(root->left, curred, res);
        string rstr = tree2str(root->right, curred, res);
        if(lstr != ""){
            if(curred.find(lstr) != curred.end() && curred[lstr] == 1) 
                res.push_back(root->left);
            curred[lstr]++;
        } 
        if(rstr != ""){
            if(curred.find(rstr) != curred.end() && curred[rstr] == 1) 
                res.push_back(root->right);
            curred[rstr]++;
        }
        return to_string(root->val) + "," + lstr + "," + rstr;
    }
};