/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        if(old2new[head] != nullptr) return old2new[head];
        old2new[head] = new RandomListNode(head->label);
        old2new[head]->next = copyRandomList(head->next);
        old2new[head]->random = copyRandomList(head->random);
        return old2new[head];
    }
    
private:
    map<RandomListNode *, RandomListNode *> old2new;
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(a2b.find(head) != a2b.end()) return a2b[head];
        Node *ans = new Node(head->val);
        a2b[head] = ans;
        ans->next = copyRandomList(head->next);
        ans->random = copyRandomList(head->random);
        return ans;
    }
    
private:
    unordered_map<Node *, Node *> a2b;
};