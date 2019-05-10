/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right == nullptr){ // go parent
            Node *ans = node->parent;
            while(ans != nullptr && ans->val < node->val) ans = ans->parent;
            return ans;
        }
        else{ // go right
            Node *ans = node->right;
            while(ans->left != nullptr) ans = ans->left;
            return ans;
        }
    }
};