class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][0] = grid[0][0];
        for (int t = 1; t <= 2*n - 2; ++t) { //steps
            vector<vector<int>> dp2(n, vector<int>(n, INT_MIN));
            for (int i = max(0, t-(n-1)); i <= min(n-1, t); ++i) {
                for (int j = max(0, t-(n-1)); j <= min(n-1, t); ++j) {
                    if (grid[i][t-i] == -1 || grid[j][t-j] == -1) continue;
                    int val = grid[i][t-i];
                    if (i != j) val += grid[j][t-j];
                    for (int pi = i-1; pi <= i; ++pi)
                        for (int pj = j-1; pj <= j; ++pj)
                            if (pi >= 0 && pj >= 0)
                                dp2[i][j] = max(dp2[i][j], dp[pi][pj] + val);
                }
            }
            dp = dp2;
        }
        return max(0, dp[n-1][n-1]);
    }
};