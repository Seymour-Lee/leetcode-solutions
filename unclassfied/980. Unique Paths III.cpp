class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        vector<int> s, e;
        int zeros = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0) zeros++;
                if(grid[i][j] == 1) s = {i, j};
                if(grid[i][j] == 2) e = {i, j};
            }
        }
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        dfs(grid, visited, s[0], s[1], ans, zeros, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, 
             int i, int j, int &ans, int zeros, int cur){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1) return;
        if(visited[i][j]) return;
        if(grid[i][j] == 2){
            ans += zeros == cur? 1: 0;
            return;
        }
        if(grid[i][j] == 0) cur++;
        visited[i][j] = true;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto dir: dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(grid, visited, ni, nj, ans, zeros, cur);
        }
        visited[i][j] = false;
    }
};