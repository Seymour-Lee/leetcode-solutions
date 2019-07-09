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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *node = dummy;
        bool repeat = false;
        while(node->next){
            ListNode *front = node->next;
            ListNode *end = front->next;
            while(front && end && front->val == end->val) end = end->next;
            if(front->next != end){
                node->next = end;
                while(front != end){
                    ListNode *cur = front;
                    front = front->next;
                    delete cur;
                }
            }
            else{
                node = node->next;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        ListNode *prev = head, *curr = head;
        while(head){
            if(head->val != curr->val){
                if(prev == curr){
                    tail->next = prev;
                    tail = tail->next;
                    prev = curr = head;
                    head = head->next;
                    tail->next = nullptr;
                }
                else{
                    prev = curr = head;
                    head = head->next;
                }
            }
            else{
                curr = head;
                head = head->next;
            }
        }
        if(prev == curr){
            tail->next = prev;
            tail = tail->next;
            tail->next = nullptr;
        }
        return dummy->next;
    }
};