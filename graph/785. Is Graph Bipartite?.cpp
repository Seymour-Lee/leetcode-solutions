class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size());
        for(int i = 0; i < graph.size(); i++){
            if(visited[i] == 0 && !dfs(graph, visited, 1, i)){
                return false;
            }
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, 
             int color, int idx){
        if(visited[idx] != 0) return visited[idx] == color;
        visited[idx] = color;
        for(auto node: graph[idx]){
            if(dfs(graph, visited, -color, node) == false){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        vector<int> c(g.size(), 0);
        for(int i = 0; i < g.size(); i++) if(c[i] == 0 && dfs(g, c, i, -1) == false) return false;
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& g, vector<int> &c, int node, int color){
        if(c[node] != 0) return c[node] == color;
        c[node] = color;
        for(auto nei: g[node]){
            if(dfs(g, c, nei, -color) == false) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        c = vector<int>(g.size(), 0);
        for(int i = 0; i < g.size(); i++) if(c[i] == 0 && dfs(g, i, 1) == false) return false;
        return true;
    }
    
private:
    vector<int> c;
    
    bool dfs(vector<vector<int>> &g, int node, int color){
        if(c[node] != 0) return c[node] == color;
        c[node] = color;
        for(auto nei: g[node]) if(dfs(g, nei, -color) == false) return false;
        return true;
    }
};