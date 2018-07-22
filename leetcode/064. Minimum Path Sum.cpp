class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size(), grid[0][0]));
        for(int i = 1; i < grid.size(); i++) result[i][0] = grid[i][0] + result[i-1][0];
        for(int i = 1; i < grid[0].size(); i++) result[0][i] = grid[0][i] + result[0][i-1];
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[i].size(); j++){
                result[i][j] = grid[i][j] + min(result[i-1][j], result[i][j-1]);
            }
        }
        return result.back().back();
    }
};