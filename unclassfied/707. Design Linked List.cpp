class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new ListNode(-1);
        maxIndex = -1;
        tail = dummy;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index > maxIndex) return -1;
        ListNode *cur = dummy->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
        maxIndex++;
        if(tail == dummy) tail = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        tail->next = node;
        tail = node;
        maxIndex++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == maxIndex + 1) addAtTail(val);
        else if(index > maxIndex + 1) return;
        else{
            ListNode *prev = dummy;
            while(index--) prev = prev->next;
            ListNode *toInsert = new ListNode(val);
            toInsert->next = prev->next;
            prev->next = toInsert;
            maxIndex++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index > maxIndex) return;
        bool isTail = (index == maxIndex);
        ListNode *prev = dummy;
        while(index--) prev = prev->next;
        if(isTail) tail = prev;
        ListNode *toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        maxIndex--;
    }
    
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    ListNode *dummy;
    int maxIndex;
    ListNode *tail;
    
    void printList(){
        ListNode *cur = dummy;
        while(cur){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */