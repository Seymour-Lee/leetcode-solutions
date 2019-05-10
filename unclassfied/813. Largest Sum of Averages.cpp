class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> dp(n, 0);
        vector<double> sum(n+1, 0);
        for(int i = 0; i < n; i++)
            sum[i+1] = sum[i] + A[i];
        for(int i = 0; i < n; i++)
            dp[i] = (sum[n] - sum[i]) / (n - i);
        for(int k = 0; k < K-1; k++){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    dp[i] = max(dp[i], (sum[j] - sum[i]) / (j - i) + dp[j]);
                }
            }
        }
        return dp[0];
    }
};