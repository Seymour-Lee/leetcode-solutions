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
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        int c = 0;
        while(l1 || l2){
            int a = l1 == nullptr? 0: l1->val;
            int b = l2 == nullptr? 0: l2->val;
            cur->next = new ListNode((a+b+c)%10);
            cur = cur->next;
            c = (a+b+c)/10;
            l1 = l1 == nullptr? nullptr: l1->next;
            l2 = l2 == nullptr? nullptr: l2->next;
        }
        if(c != 0) cur->next = new ListNode(c);
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        int c = 0;
        ListNode *cur = dummy;
        while(l1 || l2){
            int a = l1? l1->val: 0;
            int b = l2? l2->val: 0;
            int val = (a+b+c)%10;
            c = (a+b+c)/10;
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l1? l1->next: l1;
            l2 = l2? l2->next: l2;
        }
        if(c) cur->next = new ListNode(c);
        return dummy->next;
    }
};