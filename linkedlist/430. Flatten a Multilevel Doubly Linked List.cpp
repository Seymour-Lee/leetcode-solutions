/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;       
        head = dfs(head, nullptr);
        return head;
    }
    
private:
    Node *dfs(Node *head, Node *prev){
        if(head == nullptr) return nullptr;
        head->prev = prev;
        if(head->child){
            Node *next = head->next;
            head->next = dfs(head->child, head);
            head->child = nullptr;
            Node *end = head;
            while(end->next) end = end->next;
            end->next = dfs(next, end);
        }
        else{
            head->next = dfs(head->next, head);
        }
        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        return dfs(head).first;
    }
    
private:
    pair<Node *, Node *> dfs(Node *node){
        if(node == nullptr) return {nullptr, nullptr};
        auto l = dfs(node->child);
        auto r = dfs(node->next);
        Node *lmost = node, *rmost = node;
        node->prev = node->next = node->child = nullptr;
        if(l.first){
            rmost->next = l.first;
            l.first->prev = rmost;
            rmost = l.second;
        }
        if(r.first){
            rmost->next = r.first;
            r.first->prev = rmost;
            rmost = r.second;
        }
        return {lmost, rmost};
    }
};