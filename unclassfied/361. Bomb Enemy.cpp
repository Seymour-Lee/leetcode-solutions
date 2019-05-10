class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int rowhits = 0;
        vector<int> colhits(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 || grid[i][j-1] == 'W'){ // row
                    rowhits = 0;
                    for(int k = j; k < n && grid[i][k] != 'W'; k++)
                        rowhits += grid[i][k] == 'E';
                }
                if(i == 0 || grid[i-1][j] == 'W'){ // col
                    colhits[j] = 0;
                    for(int k = i; k < m && grid[k][j] != 'W'; k++)
                        colhits[j] += grid[k][j] == 'E';
                }
                if(grid[i][j] == '0')
                    ans = max(ans, rowhits+colhits[j]);
            }
        }
        return ans;
    }
};