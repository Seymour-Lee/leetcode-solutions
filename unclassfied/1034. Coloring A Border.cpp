class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        // ans = grid;
        dfs(grid, r0, c0, grid[r0][c0]);
        for(auto p: ans){
            // cout<<p[0]<<" "<<p[1]<<endl;
            int count = 0;
            for(auto dir: dirs){
                count += ans.find({p[0]+dir[0], p[1]+dir[1]}) != ans.end(); 
            }
            if(count != 4) grid[p[0]][p[1]] = color;
        }
        return grid;
    }
    
private:
    set<vector<int>> ans;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    set<vector<int>> seen;
    
    void dfs(vector<vector<int>>& grid, int r, int c, int ori){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return;
        if(grid[r][c] != ori) return;
        if(seen.find({r, c}) != seen.end()) return;
        seen.insert({r, c});
        ans.insert({r, c});
        for(auto dir: dirs){
            dfs(grid, r+dir[0], c+dir[1], ori); 
        }
    }
    
    // return same color as ori
//     int dfs(vector<vector<int>>& grid, int r, int c, int color, const int ori){
//         cout<<r<<" "<<c<<endl;
//         if(seen.find({r, c}) != seen.end()) return grid[r][c] == ori;
//         if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
//         seen.insert({r, c});
//         if(ans[r][c] != ori) return 0;
//         int count = 0;
//         for(auto dir: dirs){
//             count += dfs(grid, r+dir[0], c+dir[1], color, ori); 
//         }
//         if(count == 4) ans[r][c] = color;
        
//         return 1;
//     }
};