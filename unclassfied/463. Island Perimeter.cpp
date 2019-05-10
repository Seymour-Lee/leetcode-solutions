class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int lands = 0;
        int lap_sides = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    lands++;
                    if(i + 1 != grid.size() && grid[i+1][j]) lap_sides++;
                    if(j + 1 != grid[i].size() && grid[i][j+1]) lap_sides++;
                } 
            }
        }
        return 4 * lands - lap_sides * 2;
    }
};