class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        if(quiet.size() == 0) return {};
        vector<int> ans(quiet.size());
        for(int i = 0; i < quiet.size(); i++) ans[i] = quiet[i];
        vector<vector<int>> s2b(quiet.size());
        for(auto r: richer) s2b[r[1]].push_back(r[0]);
        vector<bool> seen(quiet.size(), false);
        for(int i = 0; i < quiet.size(); i++){
            if(seen[i] == true) continue;
            dfs(i, quiet, s2b, seen, ans);
        }
        return ans;
    }
    
private:
     int dfs(const int pos, const vector<int> &quiet, const vector<vector<int>> &g, 
            vector<bool> &seen, vector<int> &ans){
        if(seen[pos] == true) return ans[pos];
        int res = pos;
        for(auto p: g[pos]){
            int cur = dfs(p, quiet, g, seen, ans);
            res = quiet[res] < quiet[cur]? res: cur;
        }
        seen[pos] = true;
        ans[pos] = res;
        return res;
    }
};

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        if(quiet.size() == 0) return {};
        vector<int> ans(quiet.size());
        for(int i = 0; i < quiet.size(); i++) ans[i] = quiet[i];
        vector<vector<int>> s2b(quiet.size());
        for(auto r: richer) s2b[r[1]].push_back(r[0]);
        vector<bool> seen(quiet.size(), false);
        for(int i = 0; i < quiet.size(); i++){
            if(seen[i] == true) continue;
            dfs(i, quiet, s2b, seen, ans);
        }
        return ans;
    }
    
private:
     int dfs(const int pos, const vector<int> &quiet, const vector<vector<int>> &g, 
            vector<bool> &seen, vector<int> &ans){
        if(seen[pos] == true) return ans[pos];
        int res = pos;
        for(auto p: g[pos]){
            int cur = dfs(p, quiet, g, seen, ans);
            res = quiet[res] < quiet[cur]? res: cur;
        }
        seen[pos] = true;
        ans[pos] = res;
        return res;
    }
};