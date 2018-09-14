class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp(N+W+1, 0.0);
        for(int k = K; k <= N; k++) dp[k] = 1.0;
        double s = min(N-K+1, W);
        for(int k = K-1 ; k >= 0; k--){
            dp[k] = s / W;
            s += dp[k] - dp[k+W];
        }
        return dp[0];
    }
};