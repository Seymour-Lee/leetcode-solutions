class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
            const int row = grid.size(); if (0 == row) return -1;
            const int col = grid[0].size();

            vector<vector<int> > distance(row, vector<int>(col, 0));
            vector<vector<int>> reach(row, vector<int>(col, 0));
            int building = 0;
        
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if(grid[i][j]==1) {
                       BFS(grid,i,j,distance,reach);
                        building++; 
                    }
               }
           }
        
        int res=INT_MAX;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (0 == grid[i][j] && reach[i][j] == building) {
                    res = min(res, distance[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    
    void BFS(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& distance,vector<vector<int>>& reach)
    {
        int dist = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> curLevel, nextLevel;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        
        curLevel.emplace(i, j);
        
        while (!curLevel.empty()) 
        {
            ++dist;
            while (!curLevel.empty()) 
            {
                
                int x = curLevel.front().first, y =  curLevel.front().second;
                curLevel.pop();
                
                for (auto dir : dirs) 
                {
                    int i = x + dir.first, j = y + dir.second;
                    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j]) continue;
                    if(grid[i][j]==1 || grid[i][j]==2) continue;

                    
                    distance[i][j] += dist;
                    nextLevel.emplace(i, j);
                    visited[i][j] = true;
                    reach[i][j]++;
                }
            }
            
            swap(curLevel, nextLevel);
        }
        
        return;
    }
};