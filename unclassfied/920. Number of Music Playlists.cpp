class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        const int mod = 1000000000+7;   
        vector<vector<long>> dp(L+1, vector<long>(N+1, 0));
        dp[0][0] = 1;
        for(int l = 1; l <= L; l++){
            for(int n = 1; n <= N; n++){
                dp[l][n] += dp[l-1][n-1]*(N-n+1);
                dp[l][n] += dp[l-1][n]*max(n-K, 0);
                dp[l][n] = dp[l][n] % mod;
            }
        }
        return (int)dp.back().back();
    }
};