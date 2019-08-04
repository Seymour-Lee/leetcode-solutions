class Solution {    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]) result = max(result, dfs(grid, i, j));
            }
        }
        return result;
    }
    
private:
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i-1, j) + dfs(grid, i, j-1) + dfs(grid, i+1, j) + dfs(grid, i, j+1);
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int ans = 0;
        for(int i = 0; i < g.size(); i++) for(int j = 0; j < g[0].size(); j++){
            if(g[i][j] == 1) ans = max(ans, dfs(g, i, j));
        }
        return ans;
    }
    
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int dfs(vector<vector<int>> &g, int i, int j){
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size()) return 0;
        if(g[i][j] == 0) return 0;
        int ans = 1;
        g[i][j] = 0;
        for(auto dir: dirs){
            int ii = i + dir[0], jj = j + dir[1];
            ans += dfs(g, ii, jj);
        }
        return ans;
    }
};