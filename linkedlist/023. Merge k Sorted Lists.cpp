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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode *dummy = new ListNode(INT_MIN);
        vector<int> vec;
        for(auto l: lists){
            while(l){
                vec.push_back(l->val);
                l = l->next;
            }
        }
        sort(vec.begin(), vec.end());
        ListNode *cur = dummy;
        for(auto val: vec){
            cur->next = new ListNode(val);
            cur = cur->next;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        auto f = [](const ListNode *a, const ListNode *b){return a->val > b->val;};
        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq(f);
        for(auto node: lists){
            while(node){
                pq.push(node);
                node = node->next;
            }
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(pq.empty() == false){
            auto p = pq.top(); pq.pop();
            cur->next = p;
            cur = cur->next;
            cur->next = nullptr;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        auto f = [](ListNode *a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq(f);
        for(auto l: lists) while(l) pq.push(l), l = l->next;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(pq.empty() == false){
            auto node = pq.top(); pq.pop();
            cur->next = node;
            cur = cur->next;
            cur->next = nullptr;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto f = [](ListNode *a, ListNode *b){
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq(f);
        for(auto l: lists) while(l){
            pq.push(l);
            l = l->next;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while(pq.empty() == false){
            auto node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            tail->next = nullptr;
        }
        return dummy->next;
    }
};