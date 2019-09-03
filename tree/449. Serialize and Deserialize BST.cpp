/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string result = "";
        stack<TreeNode *> stk;
        stk.push(root);
        while(stk.empty() == false){
            TreeNode *node = stk.top();
            stk.pop();
            result += "," + to_string(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return result.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        istringstream is(data);
        string str = "";
        vector<int> nums;
        while(getline(is, str, ',')) nums.push_back(stoi(str));
        TreeNode *root = new TreeNode(nums[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        for(int i = 1; i < nums.size(); i++){
            TreeNode *last = stk.empty()? nullptr: stk.top();
            while(stk.empty() == false && nums[i] > stk.top()->val){
                last = stk.top();
                stk.pop();
            }
            if(nums[i] < last->val){
                last->left = new TreeNode(nums[i]);
                stk.push(last->left);
            }
            else{
                last->right = new TreeNode(nums[i]);
                stk.push(last->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string ans = "";
        stack<TreeNode *> stk;
        stk.push(root);
        while(stk.empty() == false){
            auto node = stk.top(); stk.pop();
            ans += ","+to_string(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }
        return ans.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        string str;
        vector<int> nums;
        while(getline(is, str, ',')) nums.push_back(stoi(str));
        return build(nums, 0, nums.size());
    }
    
private:
    TreeNode *build(vector<int> &nums, int l, int r){
        if(l == r) return nullptr;
        TreeNode *root = new TreeNode(nums[l]);
        int m = l+1;
        while(m < r && nums[l] > nums[m]) m++;
        root->left = build(nums, l+1, m);
        root->right = build(nums, m, r);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));