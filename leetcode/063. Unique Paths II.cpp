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