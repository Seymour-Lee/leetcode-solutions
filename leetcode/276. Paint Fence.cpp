class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0 || (k == 1 && n > 2)) return 0;
        if(n == 1) return k;
        if(n == 2) return k*k;
        vector<int> dp(n, 0);
        dp[0] = k, dp[1] = k*k, dp[2] = k*(k*k-1);
        for(int i = 3; i < n; i++)
            dp[i] = k * (dp[i-1] - dp[i-3]*(k-1)/k);
        return dp.back();
    }
};