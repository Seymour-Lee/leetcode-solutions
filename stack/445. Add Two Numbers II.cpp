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
        stack<ListNode *> num1;
        stack<ListNode *> num2;
        ListNode *cur = l1;
        while(cur){
            num1.push(cur);
            cur = cur->next;
        }
        cur = l2;
        while(cur){
            num2.push(cur);
            cur = cur->next;
        }
        ListNode *head = nullptr;
        int carry = 0;
        int sum = 0;
        while(num1.empty() == false || num2.empty() == false){
            int a = num1.empty()? 0: num1.top()->val;
            if(num1.empty() == false) num1.pop();
            int b = num2.empty()? 0: num2.top()->val;
            if(num2.empty() == false) num2.pop();
            sum = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            cur = new ListNode(sum);
            cur->next = head;
            head = cur;
        }
        if(carry == 1){
            cur = new ListNode(1);
            cur->next = head;
            head = cur;
        }
        return head;
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
        l1 = reverseList(l1);
        l2 = reverseList(l2);
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
        
        return reverseList(dummyHead->next);
    }
    
    ListNode* reverseList(ListNode* head) {
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