class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        const int goal = (1 << n) - 1;
        const int allstates = 1 << n;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(allstates, false));
        for(int i = 0; i < n; i++) q.push({i, (1 << i)});
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto f = q.front(); q.pop();
                int node = f.first;
                int state = f.second;
                if(state == goal) return ans;
                if(visited[node][state]) continue;
                visited[node][state] = true;
                for(auto next: graph[node]) q.push({next, state | (1 << next)});
            }
            ans++;
        }
        return -1;
    }
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int target = (1<<n)-1;
        vector<vector<bool>> v(n, vector<bool>((1<<n), false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) q.push({i, 1<<i}), v[i][1<<i] = true;
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto p = q.front(); q.pop();
                int node = p.first;
                int state = p.second;
                if(state == target) return ans;
                for(auto nei: g[node]) if(v[nei][state | (1 << nei)] == false){
                    v[nei][state | (1 << nei)] = true;
                    q.push({nei, state|(1<<nei)});
                }
            }
            ans++;
        }
        return -1;
    }
};