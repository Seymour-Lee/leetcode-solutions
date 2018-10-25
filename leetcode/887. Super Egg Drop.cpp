// TLE
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
        for(int n = 1; n <= N; n++) dp[n][1] = n;
        for(int k = 1; k <= K; k++) dp[1][k] = 1;
        for(int n = 2; n <= N; n++){
            for(int k = 2; k <= K; k++){
                dp[n][k] = INT_MAX;
                for(int n1 = 1; n1 < n; n1++){
                    dp[n][k] = min(dp[n][k], max(dp[n1-1][k-1], dp[n-n1][k])+1);
                }
            }
        }
        return dp.back().back();
    }
};