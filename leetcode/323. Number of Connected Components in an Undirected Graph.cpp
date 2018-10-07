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