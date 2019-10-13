class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // int[][][] dp = new int[n + 1][6][16];
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(6, vector<int>(16)));
        int temp = 0;
        for (int i = 0; i < 6; i++) {
            dp[1][i][1] = 1;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = rollMax[j]; k >= 2; k--) {
                    dp[i][j][k] = dp[i - 1][j][k - 1];
                }
                
                int sum = 0;
                for (int h = 0; h < 6; h++) {
                    if (h == j) continue;
                    for (int k = rollMax[h]; k >= 1; k--) {
                        sum += dp[i - 1][h][k];
                        sum %= mod;
                    }
                }
                
                dp[i][j][1] = sum;
            }
        }
        
        int sum = 0;
        for (int h = 0; h < 6; h++) {
            for (int k = rollMax[h]; k >= 1; k--) {
                sum += dp[n][h][k];
                sum %= mod;
            }
        }
        
        return sum;
    }
    
private:
    // vector<vector<int>> memo;
    int mod = 1e9+7;
    
    // int dp(int n, vector<int>& roll){
    //     if(n == 0 || roll == vector<int>{0, 0, 0, 0, 0, 0}) return;
    //     for(int i = 0; i < roll.size(); i++) if(roll[i]){
    //         roll[i]--;
    //         memo[n][i] = dp(n-1, roll);
    //         roll[i]++;
    //     }
    //     return memo[]
    // }
};