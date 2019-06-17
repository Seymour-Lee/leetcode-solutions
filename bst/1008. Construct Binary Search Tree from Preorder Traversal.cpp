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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = 0;
        return divide(preorder, pos, INT_MIN, INT_MAX);
    }
    
private:
    TreeNode *divide(vector<int> &p, int &pos, int minval, int maxval){
        if(pos == p.size()) return nullptr;
        int val = p[pos];
        if(val < minval || val > maxval) return nullptr;
        TreeNode *root = new TreeNode(val);
        pos++;
        root->left = divide(p, pos, minval, val-1);
        root->right = divide(p, pos, val+1, maxval);
        
        return root;
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
    TreeNode* bstFromPreorder(vector<int>& p) {
        if(p.size() == 0) return nullptr;
        TreeNode *node = new TreeNode(p[0]);
        int pos = 1;
        while(pos < p.size() && p[pos] < node->val) pos++;
        auto l = vector<int>(p.begin()+1, p.begin()+pos);
        auto r = vector<int>(p.begin()+pos, p.end());
        node->left = bstFromPreorder(l);
        node->right = bstFromPreorder(r);
        return node;
    }
};