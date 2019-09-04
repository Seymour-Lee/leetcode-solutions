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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        dummy = new ListNode(-1);
        dummy->next = head;
        length = 0;
        while(head){
            length++;
            head = head->next;
        }
        srand(time(0));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand() % length;
        ListNode *node = dummy->next;
        while(idx--) node = node->next;
        return node->val;
    }
    
private:
    ListNode *dummy;
    int length;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        dummy->next = head;
        while(head) head = head->next, len++;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand() % len;
        ListNode *node = dummy->next;
        while(pos--) node = node->next;
        return node->val;
    }
    
private:
    ListNode *dummy = new ListNode(-1);
    int len = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */