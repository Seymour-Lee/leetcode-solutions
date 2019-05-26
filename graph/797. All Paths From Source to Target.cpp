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

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        dfs(graph, ans, {}, {}, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& ans, unordered_set<int> seen, vector<int> cur, int pos){
        seen.insert(pos);
        cur.push_back(pos);
        if(pos == g.size()-1){
            ans.push_back(cur);
            return;
        }
        for(auto nei: g[pos]){
            if(seen.find(nei) == seen.end()){
                dfs(g, ans, seen, cur, nei);
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> cur = {0};
        dfs(graph, ans, cur, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& ans, vector<int> &cur, int pos){
        if(pos == g.size()-1){
            ans.push_back(cur);
            return;
        }
        for(auto nei: g[pos]){
            cur.push_back(nei);
            dfs(g, ans, cur, nei);
            cur.pop_back();
        }
    }
};