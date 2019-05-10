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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre, *cur, *post, *tail=dummy;
        for(int i = 0; i < m-1; i++) tail = tail->next;
        pre = tail->next;
        cur = pre->next;
        for(int i = 0; i < n-m; i++){
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        tail->next->next = cur;
        tail->next = pre;
        return dummy->next;
    }
};