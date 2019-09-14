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
        TreeLinkNode *head = new TreeLinkNode(-1);
        while(root){
            head->next = nullptr;
            TreeLinkNode *cur = head;
            while(root){
                if(root->left){
                    cur->next = root->left;
                    cur = cur->next;
                }
                if(root->right){
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = head->next;
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
        Node *ans = root;
        Node *dummy = new Node(-1);
        while(root){
            dummy->next = nullptr;
            Node *cur = dummy;
            while(root){
                if(root->left){
                    cur->next = root->left;
                    cur = cur->next;
                }
                if(root->right){
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy->next;
        }
        return ans;
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
        Node *dummy = new Node(-1);
        while(node){
            dummy->next = nullptr;
            Node *cur = dummy;
            while(node){
                if(node->left){
                    cur->next = node->left;
                    cur = cur->next;
                }
                if(node->right){
                    cur->next = node->right;
                    cur = cur->next;
                }
                node = node->next;
            }
            node = dummy->next;
        }
        return root;
    }
};