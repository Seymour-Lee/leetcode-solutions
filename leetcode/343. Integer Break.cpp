class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1; dp[2] = 1;
        for(int i = 3; i < dp.size(); i++){
            int res = 0;
            for(int j = 1; j < i; j++){
                int a = max((i-j)*j, dp[i-j]*dp[j]);
                int b = max(dp[i-j]*j, (i-j)*dp[j]);
                res = max(res, max(a, b));
            }
            dp[i] = res;
        }
        return dp.back();
    }
};