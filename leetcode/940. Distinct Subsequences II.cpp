class Solution {
public:
    int distinctSubseqII(string S) {
        const long long mod = 1000000000+7;
        int n = S.size();
        vector<long long> last(256, -1);
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n ;i++){
            dp[i] = (2*dp[i-1]) % mod;
            if(last[S[i-1]] != -1) dp[i] = (dp[i] - dp[last[S[i-1]]] + mod) % mod;
            last[S[i-1]] = i-1;
        }
        return (int)(dp[n]-1);
    }
}; 