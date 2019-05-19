/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if(root == nullptr) return result;
        dfs(root, result);
        return result;
    }
    
private:
    void dfs(Node *root, vector<int> &result){
        result.push_back(root->val);
        for(auto child: root->children){
            dfs(child, result);
        }
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
private:
    void dfs(Node *root, vector<int> &ans){
        if(root == nullptr) return;
        ans.push_back(root->val);
        for(auto c: root->children) dfs(c, ans);
    }
};