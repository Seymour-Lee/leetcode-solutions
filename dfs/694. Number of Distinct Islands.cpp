class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        set<set<int>> shapes;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[r].size(); c++){
                set<int> shape = {};
                dfs(grid, seen, shape, r, c, r, c);
                if(shape.empty() == false){
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
    
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &seen, set<int> &shape,
             int r, int c, int r0, int c0){
        if (0 <= r && r < grid.size() && 0 <= c && c < grid[0].size() &&
                grid[r][c] == 1 && !seen[r][c]) {
            seen[r][c] = true;
            shape.insert((r - r0) * 2 * grid[0].size() + (c - c0));
            dfs(grid, seen, shape, r+1, c, r0, c0);
            dfs(grid, seen, shape, r-1, c, r0, c0);
            dfs(grid, seen, shape, r, c+1, r0, c0);
            dfs(grid, seen, shape, r, c-1, r0, c0);
        }
    }
};

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& g) {
        set<set<string>> ans;
        for(int i = 0; i < g.size(); i++) for(int j = 0; j < g[i].size(); j++){
            if(g[i][j]){
                set<string> cur = {};
                dfs(g, i, j, i, j, cur);
                ans.insert(cur);
            }
        }
        return ans.size();
    }

private:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>> &g, int i, int j, int i0, int j0, set<string> &cur){
        if(i < 0 || i >= g.size() || j < 0 || j >= g[i].size()) return;
        if(g[i][j] == 0) return;
        string str = to_string(i-i0)+","+to_string(j-j0);
        if(cur.find(str) != cur.end()) return;
        cur.insert(str);
        g[i][j] = 0;
        for(auto dir: dirs){
            int ii = i+dir[0], jj = j+dir[1];
            dfs(g, ii, jj, i0, j0, cur);
        }
    }
};