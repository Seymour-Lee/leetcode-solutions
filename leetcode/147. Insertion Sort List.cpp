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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = nullptr;
        while(head){
            ListNode *prev = dummy;
            while(prev->next && prev->next->val <= head->val) prev = prev->next;
            ListNode *next = prev->next;
            prev->next = head;
            head = head->next;
            prev->next->next = next;
        }
        return dummy->next;
    }
};