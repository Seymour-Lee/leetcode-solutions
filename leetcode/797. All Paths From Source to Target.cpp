class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        dfs(graph, result, vector<int>(), 0, graph.size()-1);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &result, 
             vector<int> path, int cur, int target){
        if(cur == target){
            path.push_back(cur);
            result.push_back(path);
            return;
        }
        path.push_back(cur);
        for(auto node: graph[cur]){
            dfs(graph, result, path, node, target);
        }
    }
};