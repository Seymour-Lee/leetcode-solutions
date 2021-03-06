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
    ListNode* plusOne(ListNode* head) {
        if(head == nullptr) return new ListNode(1);
        head = reverse(head);
        ListNode *cur = head;
        int carry = (cur->val+1) / 10;
        cur->val = (cur->val+1) % 10;
        cur = cur->next;
        while(carry && cur){
            int sum = cur->val+carry;
            carry = sum / 10;
            cur->val = sum % 10;
            cur = cur->next;
        }
        head = reverse(head);
        if(carry){
            ListNode *node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }
    
private:
    ListNode *reverse(ListNode *head){
        ListNode *dummy = new ListNode(-1);
        ListNode *node = nullptr;
        while(head){
            dummy->next = head;
            head = head->next;
            dummy->next->next = node;
            node = dummy->next;
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
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        int c = 1;
        ListNode *node = head;
        while(node){
            int val = node->val+c;
            node->val = val % 10;
            c = val / 10;
            node = node->next;
        }
        head = reverse(head);
        if(c){
            node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }
    
private:
    ListNode *reverse(ListNode *head){
        ListNode *dummy = new ListNode(-1);
        while(head){
            ListNode *node = head;
            head = head->next;
            node->next = dummy->next;
            dummy->next = node;
        }
        
        return dummy->next;
    }
};