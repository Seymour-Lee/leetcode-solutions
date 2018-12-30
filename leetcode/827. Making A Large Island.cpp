class Solution {
public:
    int largestIsland(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        p = vector<int>(m*n, -1);
        c = vector<int>(m*n, 1);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(g[i][j]){
            if(v(i+1, j) && g[i+1][j]) u(idx(i, j), idx(i+1, j));
            if(v(i, j+1) && g[i][j+1]) u(idx(i, j), idx(i, j+1));
        }
        int ans = 0;
        for(int i = 0; i < p.size(); i++) if(p[i] == -1) ans = max(ans, c[i]);
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(g[i][j] == 0){
            unordered_set<int> ls = {};
            for(auto d: dir){
                int nx = i + d[0];
                int ny = j + d[1];
                if(v(nx, ny) && g[nx][ny]) ls.insert(f(idx(nx, ny)));
            }
            int cnt = 1;
            for(auto l: ls) cnt += c[l];
            ans = max(cnt, ans);
        }
        return ans;
    }
    
private:
    int m;
    int n;
    vector<int> p;
    vector<int> c;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int idx(int i, int j){return i * n + j;}
    
    bool v(int i, int j){
        return 0 <= i && i < m && 0 <= j && j < n;
    }
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    void u(int x, int y){
        int px = f(x);
        int py = f(y);
        if(px != py) p[px] = py, c[py] += c[px];
    }
};