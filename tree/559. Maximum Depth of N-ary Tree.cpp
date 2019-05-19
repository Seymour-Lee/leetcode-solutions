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
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int maxChildrenDepth = 1;
        for(auto child: root->children){
            maxChildrenDepth = max(maxChildrenDepth, maxDepth(child) + 1);
        }
        return maxChildrenDepth;
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
    int maxDepth(Node* root) {
        int ans = 0;
        dfs(root, 1, ans);
        return ans;
    }

private:
    void dfs(Node *root, int level, int &ans){
        if(root == nullptr) return;
        ans = max(ans, level);
        for(auto c: root->children) dfs(c, level+1, ans);
    }
};