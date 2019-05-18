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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr ){
            return l2;
        }

        if(l2 == nullptr){
            return l1;
        }
        
        ListNode *dummy = new ListNode(0);
        
        ListNode *cur = dummy;
        while(true){
            if(l1-> val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            
            if(l1 == nullptr){
                cur->next = l2;
                break;
            }
            else if(l2 == nullptr){
                cur->next = l1;
                break;
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val) cur->next = l1, cur = cur->next, l1 = l1->next;
            else cur->next = l2, cur = cur->next, l2 = l2->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *node = dummy;
        while(l1 || l2){
            int a = l1? l1->val: INT_MAX;
            int b = l2? l2->val: INT_MAX;
            if(a < b) node->next = l1, l1 = l1->next;
            else node->next = l2, l2 = l2->next;
            node = node->next, node->next = nullptr;
        }
        return dummy->next;
    }
};