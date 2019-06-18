/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        node = root;
        while(node){
            stk.push(node);
            node = node-> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext(){
        return stk.empty() == false;
    }

    /** @return the next smallest number */
    int next() {
        int result = stk.top()->val;
        node = stk.top()->right;
        stk.pop();
        while(node){
            stk.push(node);
            node = node->left;
        }
        return result;
    }
    
private:
    stack<TreeNode *> stk;
    TreeNode *node;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto node = stk.top();
        stk.pop();
        int ans = node->val;
        node = node->right;
        while(node){
            stk.push(node);
            node = node->left;
        }
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.empty() == false;
    }
    
private:
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */