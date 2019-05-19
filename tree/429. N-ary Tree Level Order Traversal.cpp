/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size--){
                Node *node = q.front();
                level.push_back(node->val);
                q.pop();
                for(auto child: node->children){
                    q.push(child);
                }
            }
            result.push_back(level);
            level.clear();
        }
        return result;
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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            vector<int> cur;
            while(size--){
                auto node = q.front(); q.pop();
                cur.push_back(node->val);
                for(auto c: node->children) q.push(c);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};