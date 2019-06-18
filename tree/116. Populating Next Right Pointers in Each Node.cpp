/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *start = root;
        while(start != nullptr){
            TreeLinkNode *cur = start;
            while(cur){
                if(cur->left) cur->left->next = cur->right;
                if(cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *node = root;
        while(node){
            Node *cur = node;
            while(cur){
                if(cur->left) cur->left->next = cur->right;
                if(cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            node = node->left;
        }
        return root;
    }
};