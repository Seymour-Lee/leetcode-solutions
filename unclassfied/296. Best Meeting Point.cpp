class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<int> rows;
        vector<int> cols;
        for(int i = 0; i < grid.size(); i++) 
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1) rows.push_back(i), cols.push_back(j);
        sort(cols.begin(), cols.end());
        int midrow = rows[rows.size()/2];
        int midcol = cols[cols.size()/2];
        int ans = 0;
        for(auto row: rows) ans += abs(row - midrow);
        for(auto col: cols) ans += abs(col - midcol);
        return ans;
    }
};