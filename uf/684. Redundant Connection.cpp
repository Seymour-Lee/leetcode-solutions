class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
        vector<int> parent(edges.size()+1, 0);
        for(int i = 0; i < parent.size(); i++) parent[i] = i;
        for(auto v: edges){
            int n1 = v[0], n2 = v[1];
            while(n1 != parent[n1]) n1 = parent[n1];
            while(n2 != parent[n2]) n2 = parent[n2];
            if(n1 == n2) result = v;
            else parent[n1] = n2;
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size(), -1);
        for(auto e: edges){
            if(u(p, e[0]-1, e[1]-1) == false) return e;
        }
        return edges.back();
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    bool u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp){
            p[xp] = yp;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        p = vector<int>(edges.size(), -1);
        for(auto e: edges){
            if(u(e[0]-1, e[1]-1) == false) return e;
        }
        return {-1, -1};
    }
    
private:
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    bool u(int x, int y){
        int px = f(x), py = f(y);
        if(px == py) return false;
        p[px] = py;
        return true;
    }
};