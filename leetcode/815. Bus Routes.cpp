class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>> s2l;
        for(int l = 0; l < routes.size(); l++) for(auto s: routes[l]) s2l[s].insert(l);
        queue<pair<int, int>> q;
        q.push({S, 0});
        unordered_set<int> seen = {S};
        while(q.empty() == false){
            auto front = q.front(); q.pop();
            int s = front.first;
            int b = front.second;
            if(s == T) return b;
            for(auto l: s2l[s]){
                for(auto next: routes[l]){
                    if(seen.find(next) == seen.end()){
                        seen.insert(next);
                        q.push({next, b+1});
                    }
                }
                routes[l].clear();
            }
        }
        return -1;
    }
};