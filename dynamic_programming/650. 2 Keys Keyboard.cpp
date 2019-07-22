class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 2; i < dp.size(); i++){
            for(int j = i - 1; j > 0; j--){
                if(i % j == 0){
                    int cur = dp[j] + (i / j);
                    if(dp[i] == 0 || cur < dp[i])
                        dp[i] = cur;
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0, dp[1] = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(i % j == 0){
                    dp[i] = min(dp[j] + i/j, dp[i]);
                }
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++) if(i % j == 0) dp[i] = min(dp[i], dp[j]+i/j);
        }
        return dp[n];
    }
};