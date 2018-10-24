class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size()-1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < s.size(); j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0].back();
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() <= 1) return s.size();
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = s.size()-1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i+1; j < s.size(); j++){
                dp[i][j] = s[i] == s[j]?
                    dp[i+1][j-1]+2:
                    max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp.front().back();
    }
};