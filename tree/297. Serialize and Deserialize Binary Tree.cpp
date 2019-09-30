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
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
private:
    void serialize(TreeNode *root, ostringstream &out){
        if(root){
            out<<root->val<<' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else{
            out<<"# ";
        }
    }
    
    TreeNode *deserialize(istringstream &in){
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
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
        string ans = "";
        dfs1(root, ans);
        return ans;
    }
    
    void dfs1(TreeNode *root, string &ans){
        if(root == nullptr){
            ans += "# ";
            return;
        }
        ans += to_string(root->val) + " ";
        dfs1(root->left, ans);
        dfs1(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        vector<string> nodes;
        string str;
        while(getline(is, str, ' ')) nodes.push_back(str);
        int i = 0;
        return dfs2(nodes, i);
    }
    
    TreeNode *dfs2(vector<string> &nodes, int &i){
        if(i == nodes.size()) return nullptr;
        if(nodes[i] == "#"){
            i++;
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(nodes[i++]));
        root->left = dfs2(nodes, i);
        root->right = dfs2(nodes, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));