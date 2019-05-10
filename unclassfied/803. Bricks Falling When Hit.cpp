class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < hits.size(); ++i){
            if(grid[hits[i][0]][hits[i][1]]) grid[hits[i][0]][hits[i][1]] = 0;
            else hits[i][0] = -1;
        }
        
        p = vector<int>(n * m, -1);
        r = vector<int>(n * m, 0);
        cnt = vector<int>(n * m, 1);
        for(int i = 0; i < m; ++i) r[i] = 1;  
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(grid[i][j]){
                    int fx = find(i * m + j);
                    if(valid(i + 1, j) && grid[i + 1][j]){
                        int fy = find((i + 1) * m + j);
                        if(fx != fy){
                            cnt[fx] += cnt[fy];
                            r[fx] = r[fy] = r[fx] | r[fy];
                            p[fy] = fx;
                        }
                    }
                    if(valid(i, j + 1) && grid[i][j + 1]){
                        int fy = find(i * m + j + 1);
                        if(fx != fy){
                            cnt[fx] += cnt[fy];
                            r[fx] = r[fy] = r[fx] | r[fy];
                            p[fy] = fx;
                        }
                    }
                }
            }
        
        vector<int> ans = vector<int>(hits.size(), 0);
        for(int i = hits.size() - 1; i >= 0; --i){
            if(hits[i][0] == -1) continue;
            int x = hits[i][0];
            int y = hits[i][1];
            int a = find(x * m + y);
            int d = 0;
            for(int j = 0; j < 4; ++j){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(valid(nx, ny) && grid[nx][ny]){
                    int b = find(nx * m + ny);
                    if(a == b) continue;
                    if(r[b] == 0) d += cnt[b];
                    
                    cnt[a] += cnt[b];
                    r[a] = r[b] = r[a] | r[b];
                    p[b] = a;
                }
            }
            grid[x][y] = 1;
            if(r[a]) ans[i] = d;
        }
        return ans;
    }
    
private:
    vector<int> p, r, cnt;
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int find(int x){
        if(p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
    bool valid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& g, vector<vector<int>>& hits) {
        m = g.size();
        n = g[0].size();
        p = vector<int>(m*n, -1);
        r = vector<bool>(m*n, false);
        cnt = vector<int>(m*n, 1);
        for(auto &h: hits){
            if(g[h[0]][h[1]]) g[h[0]][h[1]] = 0;
            else h[0] = -1;
        }
        for(int j = 0; j < g[0].size(); j++) r[idx(0, j)] = true;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 0) continue;
                if(v(i+1, j) && g[i+1][j]) u(idx(i, j), idx(i+1, j));
                if(v(i, j+1) && g[i][j+1]) u(idx(i, j), idx(i, j+1));
            }
        }
        vector<int> ans(hits.size(), 0);
        for(int i = hits.size()-1; i >= 0; i--){
            auto h = hits[i];
            if(h[0] == -1) continue;
            int x = h[0], y = h[1];
            int num = 0;
            for(auto d: dir){
                int nx = x + d[0];
                int ny = y + d[1];
                if(v(nx, ny) && g[nx][ny]){
                    num += u(idx(x, y), idx(nx, ny));
                }
            }
            g[x][y] = 1;
            if(r[idx(x, y)]) ans[i] = num;
        }
        return ans;
    }
    
private:
    int m;
    int n;
    vector<int> p;
    vector<bool> r;
    vector<int> cnt;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool v(int i, int j){
        return 0 <= i && i < m && 0 <= j && j < n;
    }
    
    int idx(int i, int j){return i * n + j;};
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    int u(int x, int y){
        int px = f(x);
        int py = f(y);
        if(px == py) return 0;
        int cnty = r[py]? 0: cnt[py];
        cnt[px] += cnt[py];
        r[px] = r[py] = r[px] || r[py];
        p[py] = px;
        return cnty;
    }
};