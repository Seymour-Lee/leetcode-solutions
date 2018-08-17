class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = s1.size()-1; i >= 0; i--) 
            dp[i][s2.size()] = dp[i+1][s2.size()] + s1[i];
        for(int i = s2.size()-1; i >= 0; i--)
            dp[s1.size()][i] = dp[s1.size()][i+1] + s2[i];
        for(int i = s1.size()-1; i >= 0; i--){
            for(int j = s2.size()-1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min(dp[i+1][j] + s1[i], dp[i][j+1] + s2[j]);
                }
            }
        }
        return dp[0][0];
    }
};