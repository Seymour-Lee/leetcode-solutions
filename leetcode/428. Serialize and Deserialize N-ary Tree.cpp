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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        ostringstream os;
        s(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream is(data);
        return d(is);
    }
    
private:
    void s(Node *root, ostringstream &os){
        if(root == nullptr) {os<<"#"; return;}
        os<<root->val<<" "<<root->children.size()<<" ";
        for(auto kid: root->children) s(kid, os);
    }
    
    Node* d(istringstream &is){
        string val = "";
        string size = "";
        is >> val;
        if(val == "#") return nullptr;
        is>>size;
        Node *node = new Node(stoi(val), {});
        for(int i = 0; i < stoi(size); i++) node->children.push_back(d(is));
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));