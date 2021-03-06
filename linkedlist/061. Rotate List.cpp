/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(k == 0) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int length = 1;
        ListNode *cur = head;
        while(cur->next) {length++; cur = cur->next;}
        ListNode *tail = cur;
        int counter = length - (k % length);
        if(counter == length) return head;
        cur = dummy;
        while(counter--) cur = cur->next;
        dummy->next = cur->next;
        tail->next = head;
        cur->next = nullptr;
        return dummy->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int len = 0;
        while(head) len++, head = head->next;
        k = k % len; k = len - k;
        if(k == len) return dummy->next; 
        head = dummy;
        while(k--) head = head->next;
        ListNode *node = head;
        head = head->next;
        node->next = nullptr;
        node = head;
        while(node->next) node = node->next;
        node->next = dummy->next;
        dummy->next = head;
        return dummy->next;
    }
};