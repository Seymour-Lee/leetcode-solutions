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