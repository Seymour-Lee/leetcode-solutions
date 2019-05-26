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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while(cur->next){
            if(cur->next->val == val){
                ListNode *node = cur->next;
                cur->next = node->next;
                delete node;
            }
            else{
                cur = cur->next;
            }
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while(head){
            ListNode *cur = head;
            head = head->next;
            cur->next = nullptr;
            if(cur->val != val) tail->next = cur, tail = tail->next;
        }
        return dummy->next;
    }
};