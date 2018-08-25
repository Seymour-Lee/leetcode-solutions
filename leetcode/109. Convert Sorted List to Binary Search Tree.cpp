/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        pair<ListNode *, ListNode *> spl = splite(head);
        ListNode *left = spl.first;
        ListNode *right = spl.second;
        TreeNode *root = new TreeNode(right->val);
        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right->next);
        return root;
    }
    
private:
    pair<ListNode *, ListNode *> splite(ListNode *head){
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *l1 = head;
        ListNode *l2 = slow->next;
        slow->next = nullptr;
        return pair<ListNode *, ListNode *>{l1, l2};
    }
};