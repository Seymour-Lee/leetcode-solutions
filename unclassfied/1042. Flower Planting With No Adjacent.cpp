class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> g;
        for(auto p: paths){
            g[p[0]-1].push_back(p[1]-1);
            g[p[1]-1].push_back(p[0]-1);
        }
        vector<int> ans(N, 0);
        dfs(g, 4, ans, 0);
        return ans;
    }
    
private:
    bool isSafe (int v, unordered_map<int, vector<int>> &graph, vector<int> &color, int c) { 
        for(auto nei: graph[v]) if(c == color[nei]) return false;
        // for (int i = 0; i < graph.size(); i++) 
        //     if (graph[v][i] && c == color[i]) 
        //         return false; 
        return true; 
    } 
    bool dfs(unordered_map<int, vector<int>> &graph, int m, vector<int> &color, int v) { 
        if (v == color.size()) return true; 
        for (int c = 1; c <= m; c++) { 
            if (isSafe(v, graph, color, c)) { 
               color[v] = c; 
               if (dfs (graph, m, color, v+1) == true) return true; 
               color[v] = 0; 
            } 
        }
        return false; 
    }
};