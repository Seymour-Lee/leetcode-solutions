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