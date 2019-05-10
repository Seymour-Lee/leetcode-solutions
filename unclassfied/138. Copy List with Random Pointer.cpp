/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        if(old2new[head] != nullptr) return old2new[head];
        old2new[head] = new RandomListNode(head->label);
        old2new[head]->next = copyRandomList(head->next);
        old2new[head]->random = copyRandomList(head->random);
        return old2new[head];
    }
    
private:
    map<RandomListNode *, RandomListNode *> old2new;
};