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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode *> result;
        if(root == nullptr) return vector<ListNode *>(k, nullptr);
        ListNode *cur = root;
        int length = 0;
        while(cur){length++; cur = cur->next;}
        vector<int> splite(k, 0);
        int less = length / k;
        int greater = length % k;
        for(int i = 0; i < splite.size(); i++){
            splite[i] = i < greater? less+1: less;
        }
        cur = root;
        for(auto l: splite){
            if(l == 0){ 
                result.push_back(nullptr);
                continue;
            }
            ListNode *head = cur;
            while(l > 1 && cur) {cur = cur->next; l--;}
            ListNode *end = cur;
            cur = cur? cur->next: nullptr;
            if(end) end->next = nullptr;
            result.push_back(head);
        }
        return result;
    }
};