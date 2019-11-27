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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *node = dummy;
        while(l1 || l2){
            int a = l1? l1->val: INT_MAX;
            int b = l2? l2->val: INT_MAX;
            if(a < b) node->next = l1, l1 = l1->next;
            else node->next = l2, l2 = l2->next;
            node = node->next;
            node->next = nullptr;
        }
        return dummy->next;
    }  
};