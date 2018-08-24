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