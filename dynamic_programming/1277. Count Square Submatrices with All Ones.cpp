class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        vector<vector<int>> dp(m.size(), vector<int>(m[0].size(), 0));
        for(int i = 0; i < m.size(); i++) dp[i][0] = m[i][0];
        for(int j = 0; j < m[0].size(); j++) dp[0][j] = m[0][j];
        for(int i = 1; i < m.size(); i++) for(int j = 1; j < m[0].size(); j++){
            dp[i][j] = m[i][j];
            if(dp[i-1][j] && dp[i-1][j-1] && dp[i][j-1] && dp[i][j]){
                dp[i][j] += min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        int ans = 0;
        for(auto &r: dp) for(auto e: r) ans += e; 
        return ans;
    }
};