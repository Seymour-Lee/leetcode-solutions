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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *consider = head->next;
        
        while(consider){
            if(consider->val == head->val){
                head->next = consider->next;
                delete consider;
                consider = head->next;
            }
            else{
                consider = consider->next;
                head = head->next;
            }
        }
        
        return dummy->next;
    }
};