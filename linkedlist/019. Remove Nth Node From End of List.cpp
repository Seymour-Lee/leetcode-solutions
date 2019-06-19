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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *end = dummy;
        while(n--) end = end->next;
        ListNode *front = dummy;
        while(end->next){
            front = front->next;
            end = end->next;
        }
        end = front->next;
        front->next = end->next;
        delete end;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        while(n--) fast = fast->next;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *faster = dummy, *slower = dummy;
        while(n--) faster = faster->next;
        while(faster->next) slower = slower->next, faster = faster->next;
        slower->next = slower->next->next;
        return dummy->next;
    }
};