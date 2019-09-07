class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0? matrix[0].size(): 0;
        if(rows == 0 || cols == 0) return 0;
        int ans = 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        for(int r = 1; r <= rows; r++){
            for(int c = 1; c <= cols; c++){
                if(matrix[r-1][c-1] == '1'){
                    dp[r][c] = min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1])+1;
                    ans = max(ans, dp[r][c]);
                }
            }
        }
        return ans * ans;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        if(m.size() == 0 || m[0].size() == 0) return 0;
        int ans = 0;
        vector<vector<int>> dp(m.size()+1, vector<int>(m[0].size()+1, 0));
        for(int i = 1; i < dp.size(); i++) for(int j = 1; j < dp[i].size(); j++){
            if(m[i-1][j-1] == '1'){
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};