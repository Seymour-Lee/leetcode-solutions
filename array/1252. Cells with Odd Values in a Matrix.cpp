class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> g(n, vector<int>(m, 0));
        for(auto &idx: indices){
            int row = idx[0], col = idx[1];
            for(int r = 0; r < n; r++) g[r][col]++;
            for(int c = 0; c < m; c++) g[row][c]++;
        }
        int ans = 0;
        for(auto &r: g) for(auto e: r) if(e % 2) ans++;
        return ans;
    }
};