/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
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

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(root == nullptr) return nullptr;
        TreeNode *ans = new TreeNode(root->val);
        if(root->children.size()) ans->left = encode(root->children[0]);
        TreeNode *cur = ans->left;
        for(int i = 1; i < root->children.size(); i++){
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return ans;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(root == nullptr) return nullptr;
        Node *ans = new Node();
        ans->val = root->val;
        TreeNode *cur = root->left;
        while(cur != nullptr){
            ans->children.push_back(decode(cur));
            cur = cur->right;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));