class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int result = 0;
        vector<int> top(grid.size(), 0);
        vector<int> left(grid.size(), 0);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                top[j] = max(top[j], grid[i][j]);
                left[i] = max(left[i], grid[i][j]);
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                result += min(top[i], left[j]) - grid[i][j];
            }
        }
        return result;
    }
};