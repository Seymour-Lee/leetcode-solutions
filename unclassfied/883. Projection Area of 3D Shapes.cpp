class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0; 
        int result = 0;
        for(auto row: grid){
            int tallest = 0;
            for(auto elem: row){
                if(elem > 0) result++;
                tallest = max(tallest, elem);
            }
            result += tallest;
        }
        for(int i = 0; i < grid[0].size(); i++){
            int tallest = 0;
            for(int j = 0; j < grid.size(); j++){
                tallest = max(tallest, grid[j][i]);
            }
            result += tallest;
        }
        return result;
    }
};