class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        map<int, vector<pair<int, int>>>g;
        for(auto f: flights)
            g[f[0]].push_back({f[1], f[2]});
        int ans = INT_MAX;
        queue<pair<int, int>> q;
        q.push({src, 0});
        int steps = 0;
        while(q.empty() == false){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto curr = q.front(); q.pop();
                if(curr.first == dst) ans = min(ans, curr.second);
                for(auto x: g[curr.first]){
                    if(x.second + curr.second > ans) continue;
                    q.push({x.first, curr.second + x.second});
                }
            }
            if(steps++ > K) break;
        }
        return ans == INT_MAX? -1: ans;
    }
};