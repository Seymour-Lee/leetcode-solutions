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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *less = new ListNode(-1);
        ListNode *greater = new ListNode(-1);
        ListNode *le = less;
        ListNode *ge = greater;
        while(head){
            ListNode *cur = head;
            head = head->next;
            if(cur->val >= x){
                ge->next = cur;
                ge = ge->next;
            }
            else{
                le->next = cur;
                le = le->next;
            }
            cur->next = nullptr;
        }
        le->next = greater->next;
        return less->next;
    }
};