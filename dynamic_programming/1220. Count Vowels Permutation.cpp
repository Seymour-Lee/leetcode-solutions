class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        dp[1] = {1, 1, 1, 1, 1};
        for(int i = 2; i <= n; i++){
            dp[i][0] = ((dp[i-1][1]+dp[i-1][2])%mod + dp[i-1][4])%mod; // a 
            dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod; // e
            dp[i][2] = (dp[i-1][1]+dp[i-1][3])%mod; // i 
            dp[i][3] = dp[i-1][2]; // o 
            dp[i][4] = (dp[i-1][2]+dp[i-1][3])%mod; // u 
        }
        int ans = 0;
        for(auto a: dp[n]) ans = (ans + a) % mod;
        return ans;
    }
};