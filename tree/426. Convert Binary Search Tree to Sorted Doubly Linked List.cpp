/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        auto ans = dfs(root);
        ans.first->left = ans.second;
        ans.second->right = ans.first;
        return ans.first;
    }
    
private:
    pair<Node *, Node *> dfs(Node *root){
        if(root == nullptr) return {nullptr, nullptr};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        Node *head = nullptr, *tail = nullptr;
        if(left.first != nullptr){
            head = left.first;
            left.second->right = root;
            root->left = left.second;
        }
        else{
            head = root;
            root->left = nullptr;
        }
        if(right.first != nullptr){
            tail = right.second;
            root->right = right.first;
            right.first->left = root;
        }
        else{
            tail = root;
            root->right = nullptr;
        }
        return {head, tail};
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        auto p = dfs(root);
        auto l = p.first;
        auto r = p.second;
        if(l != nullptr){
            l->left = r;
            r->right = l;
        }
        return l;
    }
    
private:
    pair<Node *, Node *> dfs(Node *root){
        if(root == nullptr) return {nullptr, nullptr};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        Node *lmost = root, *rmost = root;
        root->left = root->right = nullptr;
        if(l.first){
            lmost = l.first;
            l.first->left = nullptr;
            l.second->right = root;
            root->left = l.second;
        }
        if(r.first){
            rmost = r.second;
            r.first->left = root;
            root->right = r.first;
        }
        return {lmost, rmost};
    }
};


