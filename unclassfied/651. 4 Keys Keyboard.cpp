class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N+1, 0);
        for(int i = 1; i <= N; i++){
            dp[i] = dp[i-1]+1;
            for(int j = 0; j < i-1; j++)
                dp[i] = max(dp[i], dp[j]*(i-j-1));
        }
        return dp.back();
    }
};

class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N+1, 0);
        for(int i = 1; i <= N; i++){
            dp[i] = dp[i-1]+1;
            for(int j = 0; j < i-1; j++){
                dp[i] = max(dp[i], dp[j]*(i-j-1));
            }
            
        }
        return dp.back();
    }
};