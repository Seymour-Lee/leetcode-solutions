/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *insertNode = new Node(insertVal, nullptr);
        if(head == nullptr) return insertNode;
        Node *cur = head;
        while(cur->next != head){
            if((cur->val <= insertVal && insertVal < cur->next->val) || 
               (cur->val < insertVal && insertVal <= cur->next->val) ||
               (cur->val > cur->next->val && (insertVal <= cur->next->val 
                                              || cur->val <= insertVal))){
                Node *next = cur->next;
                cur->next = insertNode;
                insertNode->next = next;
                return head;
            }
            cur = cur->next;
        }
        Node *next = cur->next;
        cur->next = insertNode;
        insertNode->next = next;
        return head;
    }
};