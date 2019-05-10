class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1, vector<int>{});
        vector<int> color(N+1, 0);
        for(auto dis: dislikes){
            graph[dis[0]].push_back(dis[1]);
            graph[dis[1]].push_back(dis[0]);
        }
        for(int i = 1; i < color.size(); i++){
            if(color[i] == 0 && dfs(graph, color, i, 1) == false){
                return false;
            }
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>> &g, vector<int> &co, int node, int color){
        co[node] = color;
        for(auto neighbor: g[node]){
            if(co[neighbor] == color) return false;
            if(co[neighbor] == 0 && dfs(g, co, neighbor, -color) == false) return false;
        }
        return true;
    }
};