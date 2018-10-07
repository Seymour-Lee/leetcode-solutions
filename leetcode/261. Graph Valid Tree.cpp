class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<int> roots(n, -1);
        for(auto edge: edges){
            unionRoot(roots, edge.first, edge.second);
        }
        for(int i = 0; i < roots.size(); i++){
            if(getRoot(roots, i) != 0) return false;
        }
        return true;
    }
    
private:
    int getRoot(vector<int> &roots, int pos){
        int root = pos;
        while(roots[root] != -1 && roots[root] != root) root = roots[root];
        return root;
    }
    
    void updateRoot(vector<int> &roots, int pos, int root){
        while(pos != -1 && roots[pos] != root){
            int next = roots[pos];
            roots[pos] = root;
            pos = next;
        }
    }
    
    void unionRoot(vector<int> &roots, int left, int right){
        int root = min(getRoot(roots, left), getRoot(roots, right));
        updateRoot(roots, left, root);
        updateRoot(roots, right, root);
    }
};