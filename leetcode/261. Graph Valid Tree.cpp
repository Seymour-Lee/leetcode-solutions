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

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> p(n, -1);
        for(auto e: edges){
            if(u(p, e.first, e.second) == false) return false;
        }
        return count(p.begin(), p.end(), -1) == 1;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    bool u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp == yp) return false;
        p[xp] = yp;
        return true;
    }
};