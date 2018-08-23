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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *odd = new ListNode(-1);
        ListNode *even = new ListNode(-1);
        ListNode *o = odd;
        ListNode *e = even;
        while(head){
            o->next = head;
            head = head->next;
            o = o->next;
            o->next = nullptr;
            if(head == nullptr) break;
            e->next = head;
            head = head->next;
            e = e->next;
            e->next = nullptr;
        }
        o->next = even->next;
        return odd->next;
    }
};