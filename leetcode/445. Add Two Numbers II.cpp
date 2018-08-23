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