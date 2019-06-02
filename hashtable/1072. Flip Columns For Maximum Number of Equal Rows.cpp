class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& m) {
        unordered_map<int, unordered_set<int>> p2s;
        for(int r0 = 0; r0 < m.size(); r0++) for(int r1 = r0+1; r1 < m.size(); r1++){
            int one = 0, zero = 0;
            for(int i = 0; i < m[r0].size(); i++){
                if(m[r0][i] == m[r1][i]) zero++;
                else one++;
            }
            if(one == m[0].size() || zero == m[0].size()){
                p2s[r0].insert(r0); p2s[r0].insert(r1);
                p2s[r1].insert(r0); p2s[r1].insert(r1);
            }
        }
        int ans = 1;
        for(auto p: p2s) ans = max(ans, (int)p.second.size());
        return ans;
    }
};

//[[0,1,1,1,0,0,0,1,0,0,0],[1,0,0,0,1,1,1,0,1,1,1],[1,0,0,0,1,0,0,0,1,0,0],[1,0,0,0,1,1,1,0,1,1,1],[1,0,0,0,1,0,0,0,1,0,0],[1,1,1,0,1,1,1,0,1,1,1]]