class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i ,j);
                    result++;
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>> &g, int i, int j){
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size()) return;
        if(g[i][j] == '0') return;
        else g[i][j] = '0';
        dfs(g, i+1, j);
        dfs(g, i-1, j);
        dfs(g, i, j+1);
        dfs(g, i, j-1);
    }
};

class Solution {
    using pint = pair<int, int>;
public:
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    p[pint{i, j}] = pint{-1, -1};
                    if(i-1 >= 0 && p.find(pint{i-1, j}) != p.end()) u(pint{i-1, j}, pint{i, j});
                    if(j-1 >= 0 && p.find(pint{i, j-1}) != p.end()) u(pint{i, j-1}, pint{i, j});
                }
            }
        }
        int ans = 0;
        for(auto v: p) if(v.second == pint{-1, -1}) ans++;
        return ans;
    }
    
private:
    map<pint, pint> p;
    
    pint f(pint x){
        if(p[x] == pint{-1, -1}) return x;
        return f(p[x]);
    }
    
    void u(pint x, pint y){
        pint xp = f(x);
        pint yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> p(m*n, -2);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    p[i*n+j] = -1;
                    if(i-1 >= 0 && p[(i-1)*n+j] != -2) u(p, i*n+j, (i-1)*n+j);
                    if(j-1 >= 0 && p[i*n+j-1] != -2) u(p, i*n+j, i*n+j-1);
                }
            }
        }
        return count(p.begin(), p.end(), -1);
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        if(g.size() == 0 || g[0].size() == 0) return 0;
        int m = g.size(), n = g[0].size();
        for(auto r: g) for(auto c: r) if(c == '1') ans++;
        p = vector<int>(m*n, -1);
        auto pos = [m, n](int r, int c){
            return r*n + c;
        };
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(g[i][j] == '1'){
            if(i-1 >= 0 && g[i-1][j] == '1') u(pos(i-1, j), pos(i, j));
            if(j-1 >= 0 && g[i][j-1] == '1') u(pos(i, j-1), pos(i, j));
        }
        return ans;
    }
    
private:
    int ans = 0;
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp, ans--;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        if(g.size() == 0 || g[0].size() == 0) return 0;
        int m = g.size(), n = g[0].size();
        for(auto r: g) for(auto c: r) if(c == '1') ans++;
        p = vector<int>(m*n, -1);
        auto pos = [m, n](int r, int c){
            return r*n + c;
        };
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(g[i][j] == '1'){
            if(i-1 >= 0 && g[i-1][j] == '1') u(pos(i-1, j), pos(i, j));
            if(j-1 >= 0 && g[i][j-1] == '1') u(pos(i, j-1), pos(i, j));
        }
        return ans;
    }
    
private:
    int ans = 0;
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp, ans--;
    }
};