class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        vector<vector<int>> dp(d.size(), vector<int>(d[0].size(), 0));
        dp.back().back() = max(1, 1-d.back().back());
        for(int j = d.back().size()-2; j >= 0; j--) dp.back()[j] = max(1, dp.back()[j+1]-d.back()[j]);
        for(int i = d.size()-2; i >= 0; i--){
            dp[i].back() = max(1, dp[i+1].back()-d[i].back());
            for(int j = d[i].size()-2; j >= 0; j--){
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-d[i][j]);
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        vector<vector<int>> dp(d.size(), vector<int>(d[0].size(), 0));
        dp.back().back() = max(1, 1-d.back().back());
        for(int j = d.back().size()-2; j >= 0; j--) dp.back()[j] = max(1, dp.back()[j+1]-d.back()[j]);
        for(int i = d.size()-2; i >= 0; i--){
            dp[i].back() = max(1, dp[i+1].back()-d[i].back());
            for(int j = d[i].size()-2; j >= 0; j--){
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1])-d[i][j]);
            }
        }
        return dp[0][0];
    }
};