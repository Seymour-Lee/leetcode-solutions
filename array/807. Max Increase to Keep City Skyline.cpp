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

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> l(n, 0);
        vector<int> b(n, 0);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            l[i] = max(grid[i][j], l[i]);
            b[j] = max(grid[i][j], b[j]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            ans += min(l[i], b[j]) - grid[i][j];
        }
        return ans;
    }
};