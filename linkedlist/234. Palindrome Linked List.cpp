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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int counter = 0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            counter += 2;
        }
        if(fast) counter++;
        if(counter % 2) slow = slow->next;
        slow = reverseList(slow);
        
        while(slow){
            if(head->val != slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
private:
    ListNode *reverseList(ListNode * head){
        ListNode *dummy = new ListNode(-1);
        while(head){
            ListNode *old = dummy->next;
            dummy->next = head;
            head = head->next;
            dummy->next->next = old;
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int counter = 0;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            counter += 2;
        }
        if(fast) counter++;
        if(counter % 2) slow = slow->next;
        slow = reverseList(slow);
        
        while(slow){
            if(head->val != slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
private:
    ListNode *reverseList(ListNode * head){
        ListNode *dummy = new ListNode(-1);
        while(head){
            ListNode *old = dummy->next;
            dummy->next = head;
            head = head->next;
            dummy->next->next = old;
        }
        return dummy->next;
    }
};