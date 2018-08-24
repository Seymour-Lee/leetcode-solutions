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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *end = dummy;
        while(n--) end = end->next;
        ListNode *front = dummy;
        while(end->next){
            front = front->next;
            end = end->next;
        }
        end = front->next;
        front->next = end->next;
        delete end;
        return dummy->next;
    }
};