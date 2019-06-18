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
        if(s.size() == 0) return nullptr;
        // cout<<s<<endl;
        int i = 0;
        while(i < s.size() && s[i] != '(') i++;
        TreeNode *node = new TreeNode(stoi(s.substr(0, i)));
        int j = i+1;
        int counter = 1;
        while(j < s.size()){
            if(s[j] == '(') counter++;
            if(s[j] == ')') counter--;
            j++;
            if(counter == 0) break;
        }
        if(i < s.size()) node->left = str2tree(s.substr(i+1, j-i-2));
        if(j+1 < s.size()) node->right = str2tree(s.substr(j+1, s.size()-j-2));
        return node;
    }
};