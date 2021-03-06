class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++) dp[i] += dp[j]*dp[i-j-1];
        }
        return dp[n];
    }
};