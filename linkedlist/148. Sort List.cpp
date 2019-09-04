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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
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
        
        l1 = sortList(l1);
        l2 = sortList(l2);
        
        ListNode *end = dummy;
        while(l1 != nullptr || l2 != nullptr){
            int val1 = l1 == nullptr? INT_MAX: l1->val;
            int val2 = l2 == nullptr? INT_MAX: l2->val;
            if(val1 <= val2){
                end->next = l1;
                l1 = l1->next;
            }
            else{
                end->next = l2;
                l2 = l2->next;
            }
            end = end->next;
            end->next = nullptr;
        }
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
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
        
        l1 = sortList(l1);
        l2 = sortList(l2);
        
        ListNode *end = dummy;
        while(l1 != nullptr || l2 != nullptr){
            int val1 = l1 == nullptr? INT_MAX: l1->val;
            int val2 = l2 == nullptr? INT_MAX: l2->val;
            if(val1 <= val2){
                end->next = l1;
                l1 = l1->next;
            }
            else{
                end->next = l2;
                l2 = l2->next;
            }
            end = end->next;
            end->next = nullptr;
        }
        return dummy->next;
    }
};