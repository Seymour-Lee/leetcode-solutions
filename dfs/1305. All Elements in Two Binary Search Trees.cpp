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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> nums1, nums2;
        dfs(root1, nums1);
        dfs(root2, nums2);
        // for(auto num: nums1) cout<<num<<" ";
        // for(auto num: nums2) cout<<num<<" ";
        int i = 0, j = 0;
        while(i < nums1.size() || j < nums2.size()){
            int val1 = (i < nums1.size()? nums1[i]: INT_MAX);
            int val2 = (j < nums2.size()? nums2[j]: INT_MAX);
            if(val1 < val2){
                ans.push_back(val1);
                i++;
            }
            else{
                ans.push_back(val2);
                j++;
            }
        }
        return ans;
    }
    
private:
    void dfs(TreeNode *root, vector<int> &nums){
        if(root == nullptr) return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
};