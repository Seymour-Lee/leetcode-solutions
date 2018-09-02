// TLE
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> result;
        int minh = INT_MAX;
        for(auto e: edges){
            graph[e.first][e.second] = true;
            graph[e.second][e.first] = true;
        }
        for(int i = 0; i != n; i++){
            int height = dfs(i, graph);
            if(height == minh) result.push_back(i);
            else if(height < minh){
                minh = height;
                result = vector<int>{i};
            }
        }
        return result;
    }
    
private:
    int dfs(int node, const vector<vector<bool>> &g){
        int n = g.size();
        vector<bool> visited(g.size(), false);
        visited[node] = true;
        queue<int> q;
        q.push(node);
        int level = 1;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                int cur = q.front(); q.pop();
                for(int i = 0; i < g[cur].size(); i++){
                    if(g[cur][i] == true && visited[i] == false){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }
};

// Peeling the leaves
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return vector<int>{0};
        vector<int> result;
        vector<set<int>> adj(n, set<int>());
        for(auto e: edges){
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }
        queue<int> q;
        for(int i = 0; i != n; i++){
            if(adj[i].size() == 1) q.push(i);
        }
        while(n > 2){
            int size = q.size();
            n = n - size;
            while(size--){
                int cur = q.front(); q.pop();
                for(auto a: adj[cur]){
                    adj[a].erase(cur);
                    if(adj[a].size() == 1) q.push(a);
                }
            }
        }
        while(q.empty() == false){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};