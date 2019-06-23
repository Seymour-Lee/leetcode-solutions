class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ans = 0;
        vector<vector<int>> g(n);
        for(auto e: edges){
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        set<int> seen;
        for(int i = 0; i < n; i++){
            if(seen.find(i) != seen.end()) continue;
            dfs(i, g, seen);
            ans++;
        }
        return ans;
    }
    
private:
    void dfs(int node, vector<vector<int>> &g, set<int> &seen){
        if(seen.find(node) != seen.end()) return;
        seen.insert(node);
        for(auto nei: g[node]){
            dfs(nei, g, seen);
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> p(n, -1);
        for(auto e: edges) u(p, e.first, e.second);
        return count(p.begin(), p.end(), -1);
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> p(n, -1);
        for(auto e: edges) u(e[0], e[1], p);
        return count(p.begin(), p.end(), -1);
    }
    
private:
    int f(int x, vector<int> &p){
        if(p[x] == -1) return x;
        return f(p[x], p);
    }
    
    void u(int x, int y, vector<int> &p){
        int xp = f(x, p);
        int yp = f(y, p);
        if(xp != yp) p[xp] = yp;
    }
};