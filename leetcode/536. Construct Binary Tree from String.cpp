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
    TreeNode* str2tree(string s) {
        if(s == "") return nullptr;
        TreeNode *root;
        int i = 0;
        while(i < s.size() && (isdigit(s[i]) || s[i] == '-')) i++;
        root = new TreeNode(stoi(s.substr(0, i)));
        
        string lstr = "";
        int lcounter = 1;
        i++;
        while(i < s.size() && lcounter != 0){
            if(s[i] == '(') lcounter++;
            if(s[i] == ')') lcounter--;
            lstr += s[i++];
        }
        lstr = lstr.size()? lstr.substr(0, lstr.size()-1): "";
        root->left = str2tree(lstr);
        
        string rstr = "";
        int rcounter = 1;
        i++;
        while(i < s.size() && rcounter != 0){
            if(s[i] == '(') rcounter++;
            if(s[i] == ')') rcounter--;
            rstr += s[i++];
        }
        rstr = rstr.size()? rstr.substr(0, rstr.size()-1): "";
        root->right = str2tree(rstr);
        
        return root;
    }
};