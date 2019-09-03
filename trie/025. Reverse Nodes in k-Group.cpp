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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *front = dummy, *rear = dummy;
        while(front->next != nullptr && rear->next != nullptr){
            for(int i = 0; i < k && rear != nullptr; i++) rear = rear->next;
            if(rear == nullptr) break;
            ListNode *next = rear->next;
            rear->next = nullptr;
            auto p = reverseList(front->next);
            front->next = p.first;
            p.second->next = next;
            front = p.second;
            rear = p.second;
        }
        return dummy->next;
    }
    
private:
    pair<ListNode *, ListNode *> reverseList(ListNode *head){
        if(head == nullptr) return {nullptr, nullptr};
        ListNode *last = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *front = dummy->next;
        while(head != nullptr){
            dummy->next = head;
            head = head->next;
            dummy->next->next = front;
            front = dummy->next;
        }
        return {dummy->next, last};
    }
};