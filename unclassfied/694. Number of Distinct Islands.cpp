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