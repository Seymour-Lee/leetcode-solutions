class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int ans = 0;
        vector<vector<int>> ps;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g[i].size(); j++){
                if(g[i][j]) ps.push_back({i, j});
            }
        }
        p = vector<int>(ps.size(), -1);
        for(int i = 0; i < ps.size(); i++){
            vector<int> &a = ps[i];
            for(int j = i+1; j < ps.size(); j++){
                vector<int> &b = ps[j];
                if(a[0] == b[0] || a[1] == b[1]) u(i, j);
            }
        }
        cout<<"a";
        unordered_map<int, int> a2n;
        for(int i = 0; i < ps.size(); i++) a2n[f(i)]++;
        for(auto pp: a2n) if(pp.second > 1) ans += pp.second;
        return ans;
    }
    
private:
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};