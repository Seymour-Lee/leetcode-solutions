class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> r2s;
        for(int i = 0; i < mat.size(); i++){
            int j = 0;
            while(j < mat[i].size() && mat[i][j]) j++;
            // cout<<i<<" "<<j<<endl;
            r2s.push_back({i, j});
        }
        // for(auto p: r2s) cout<<p.first<<" "<<p.second<<endl;
        auto f = [](pair<int, int> a, pair<int, int> b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        };
        sort(r2s.begin(), r2s.end(), f);
        for(auto p: r2s) cout<<p.first<<" "<<p.second<<endl;
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(r2s[i].first);
        return ans;
    }
};