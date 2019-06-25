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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), grid[0][0]));
        for(int i = 1; i < grid.size(); i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < grid[0].size(); j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[i].size(); j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        vector<vector<int>> dp(g.size(), vector<int>(g[0].size(), 0));
        dp[0][0] = g[0][0];
        for(int i = 1; i < g.size(); i++) dp[i][0] = dp[i-1][0] + g[i][0];
        for(int j = 1; j < g[0].size(); j++) dp[0][j] = dp[0][j-1] + g[0][j];
        for(int i = 1; i < g.size(); i++) for(int j = 1; j < g[i].size(); j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + g[i][j];
        return dp.back().back();
    }
};