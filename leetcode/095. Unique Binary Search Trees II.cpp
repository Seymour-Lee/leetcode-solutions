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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode *>();
        return build(1, n);
    }
    
private:
    vector<TreeNode *> build(int start, int end){
        vector<TreeNode *> result;
        if(end < start) return vector<TreeNode *>{nullptr};
        if(end == start) return vector<TreeNode *>{new TreeNode(end)};
        
        for(int i = start; i <= end; i++){
            vector<TreeNode *> left = build(start, i-1);
            vector<TreeNode *> right = build(i+1, end);
            for(auto l: left){
                for(auto r: right){
                    TreeNode *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};