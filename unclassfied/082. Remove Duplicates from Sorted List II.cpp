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
        ListNode *node = dummy;
        bool repeat = false;
        while(node->next){
            ListNode *front = node->next;
            ListNode *end = front->next;
            while(front && end && front->val == end->val) end = end->next;
            if(front->next != end){
                node->next = end;
                while(front != end){
                    ListNode *cur = front;
                    front = front->next;
                    delete cur;
                }
            }
            else{
                node = node->next;
            }
        }
        return dummy->next;
    }
};