class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        queue<vector<int>> q;
        q.push(source);
        set<vector<int>> b(blocked.begin(), blocked.end());
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        set<vector<int>> seen;
        int uplimit = (1+200)*200/2;
        while(q.empty() == false && seen.size() < uplimit){
            int size = q.size();
            // cout<<"size is "<<size<<endl;
            while(size--){
                auto p = q.front(); q.pop();
                // cout<<p[0]<<" "<<p[1]<<endl;
                if(p == target) return true;
                if(b.find(p) != b.end()) continue;
                if(seen.find(p) != seen.end()) continue;
                seen.insert(p);
                for(auto d: dirs){
                    int r = p[0]+d[0];
                    int c = p[1]+d[1];
                    if(r < 0 || r >= 1e6 || c < 0 || c >= 1e6) continue;
                    q.push({r, c});
                    // seen.insert({r, c});
                }
            }
        }
        return seen.size() >= uplimit;
    }
    
};