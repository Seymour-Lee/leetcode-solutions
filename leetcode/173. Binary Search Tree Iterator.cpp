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