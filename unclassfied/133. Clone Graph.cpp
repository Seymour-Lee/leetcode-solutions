/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        map<int, UndirectedGraphNode *> label2node;
        return dfs(node, label2node);
    }
    
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, 
                             map<int, UndirectedGraphNode *> &label2node){
        UndirectedGraphNode *cur = label2node[node->label];
        if(cur == nullptr){
            cur = new UndirectedGraphNode(node->label);
            label2node[node->label] = cur;
            for(auto n: node->neighbors){
                (cur->neighbors).push_back(dfs(n, label2node));
            }
        }
        return cur;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:    
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        map<int, Node *> label2node;
        return dfs(node, label2node);
    }

private:
    Node *dfs(Node *node, map<int, Node *> &label2node){
        Node *cur = label2node[node->val];
        if(cur == nullptr){
            cur = new Node(node->val);
            label2node[node->val] = cur;
            for(auto n: node->neighbors){
                (cur->neighbors).push_back(dfs(n, label2node));
            }
        }
        return cur;
    }
};