class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j, m, n, dp, matrix));
            }
        }
        return ans;
    }
    
private:
    int dfs(const int r, const int c, const int m, const int n, 
            vector<vector<int>> &dp, const vector<vector<int>> &matrix){
        if(dp[r][c] > 0) return dp[r][c];
        int ans = 1;
        vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        for(auto dir: dirs){
            int rr = r + dir[0];
            int cc = c + dir[1];
            if(rr < 0|| rr >= m || cc < 0 || cc >= n ||
               matrix[rr][cc] <= matrix[r][c]) continue;
            ans = max(ans, dfs(rr, cc, m, n, dp, matrix)+1);
        }
        dp[r][c] = ans;
        return ans;
    }
};