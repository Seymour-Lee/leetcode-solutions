class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        vector<vector<int>> result(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for(int i = 0; i < result.size() && obstacleGrid[i][0] != 1; i++) result[i][0] = 1;
        for(int i = 0; i < result[0].size() && obstacleGrid[0][i] != 1; i++) result[0][i] = 1;
        for(int i = 1; i < result.size(); i++){
            for(int j = 1; j < result[i].size(); j++){
                if(obstacleGrid[i][j]){
                    result[i][j] = 0;
                }
                else{
                    result[i][j] = result[i][j-1] + result[i-1][j];
                }
            }
        }
        return result.back().back();
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        if(a.size() == 0 || a[0].size() == 0) return 0;
        vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), 0));
        for(int i = 0; i < dp.size() && a[i][0] == 0; i++) dp[i][0] = 1;
        for(int j = 0; j < dp[0].size() && a[0][j] == 0; j++) dp[0][j] = 1;
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[i].size(); j++){
                dp[i][j] = a[i][j] == 1?
                    0:
                    dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};