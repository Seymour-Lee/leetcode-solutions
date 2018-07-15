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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        
        while(p != nullptr || q != nullptr){
            int a = p != nullptr? p->val: 0;
            int b = q != nullptr? q->val: 0;
            int sum = a + b + c;
            cur->next = new ListNode(sum % 10);
            c = sum / 10;
            cur = cur->next;
            p = p != nullptr? p->next: p;
            q = q != nullptr? q->next: q;
        }
        
        if(c > 0){
            cur->next = new ListNode(c);
        }
        
        return dummyHead->next;
    }
};