class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        map<int, vector<pair<int, int>>> adj;
        for(auto t: times) adj[t[0]].push_back({t[1], t[2]});
        map<int, int> dis;
        queue<pair<int, int>> q;
        q.push({K, 0});
        while(q.empty() == false){
            auto p = q.front(); q.pop();
            int node = p.first;
            int dist = p.second;
            if(dis.find(node) == dis.end() || dis[node] > dist){
                dis[node] = dist;
                for(auto neig: adj[node]){
                    int nei = neig.first;
                    int weight = neig.second;
                    if(dis.find(nei) == dis.end() || dis[nei] > dist + weight){
                        q.push({nei, dist + weight});
                    }
                }
            }
        }
        auto f = [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        };
        return dis.size() == N? max_element(dis.begin(), dis.end(), f)->second: -1; 
    }
};