class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> color(graph.size(), 0);
        for(decltype(graph.size()) i = 0; i < graph.size(); i++){
            if(dfs(i, color, graph))
                ans.push_back(i);
        }
        return ans;
    }
    
private:
    bool dfs(int node, vector<int> &color, vector<vector<int>> &g){
        if(color[node] > 0)
            return color[node] == 2;
        color[node] = 1;
        for(auto nei: g[node]){
            if(color[nei] == 2) continue;
            if(color[nei] == 1 || dfs(nei, color, g) == false)
                return false;
        }
        color[node] = 2;
        return true;
    }
};