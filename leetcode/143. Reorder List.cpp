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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode *dummy = new ListNode(-1);
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *l1 = head;
        ListNode *l2 = slow->next;
        slow->next = nullptr;
        l2 = reverse(l2);
        ListNode *end = dummy;
        while(l2){
            end->next = l1;
            l1 = l1->next;
            end = end->next;
            end->next = l2;
            l2 = l2->next;
            end = end->next;
            end->next = nullptr;
        }
        if(l1) end->next = l1;
        head = dummy->next;
    }
    
private:
    ListNode *reverse(ListNode *head){
        if(head == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *p;
        while(head){
            p = dummy->next;
            dummy->next = head;
            head = head->next;
            dummy->next->next = p;
        }
        return dummy->next;
    } 
};