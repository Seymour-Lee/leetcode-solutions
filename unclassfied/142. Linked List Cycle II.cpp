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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        set<ListNode *> st;
        while(head){
            if(st.find(head) != st.end()) return head;
            st.insert(head);
            head = head->next;
        }
        return nullptr;
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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        bool hascircle = false;
        while(fast && slow){
            slow = slow->next;
            if(fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            if(fast == slow){hascircle = true; break;}
        }
        if(hascircle == false) return nullptr;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};