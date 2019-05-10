class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int mod = 1e9+7;
        int dp[3][S.size()][4];
        for(int len = 1; len <= S.size(); len++){
            for(int i = 0; i + len <= S.size(); i++) for(int k = 0; k < 4; k++){
                dp[2][i][k] = 0;
                int j = i + len - 1;
                char c = 'a' + k;
                if(len == 1) dp[2][i][k] = (S[i] == c);
                else{
                    if(S[i] != c) dp[2][i][k] = dp[1][i+1][k];
                    else if(S[j] != c) dp[2][i][k] = dp[1][i][k];
                    else{
                        dp[2][i][k] = 2;
                        if(len > 2) for(int y = 0; y < 4; y++){
                            dp[2][i][k] = (dp[2][i][k] + dp[0][i+1][y]) % mod;
                        }
                    }
                }
            }
            for(int i = 0; i < 2; i++) for(int j = 0; j < S.size(); j++) for(int k = 0; k < 4; k++){
                dp[i][j][k] = dp[i+1][j][k];
            }
        }
        int ans = 0;
        for(int k = 0; k < 4; k++) ans = (ans + dp[2][0][k]) % mod;
        return ans;
    }
};