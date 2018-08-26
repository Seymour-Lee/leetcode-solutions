class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0) continue;
                result += 2;
                int up = i - 1 >= 0? grid[i-1][j]: 0;
                result += max(grid[i][j]-up, 0);
                int down = i + 1 < grid.size()? grid[i+1][j]: 0;
                result += max(grid[i][j]-down, 0);
                int left = j - 1 >= 0? grid[i][j-1]: 0;
                result += max(grid[i][j]-left, 0);
                int right = j + 1 < grid[i].size()? grid[i][j+1]: 0;
                result += max(grid[i][j]-right, 0);
            }
        }
        return result;
    }
};