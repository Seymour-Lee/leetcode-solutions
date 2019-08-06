class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));
        // dp[i][j] = max from str1[0:i] and str2[0:j]
        // dp[i][j] = max{}
        for(int j = 0; j < str2.size(); j++){
            if(str1[0] == str2[j]) dp[0][j] = 1;
            else if(j > 0) dp[0][j] = dp[0][j-1];
        }
        for(int i = 1; i < str1.size(); i++){
            if(str1[i] == str2[0]) dp[i][0] = 1;
            else if(i > 0) dp[i][0] = dp[i-1][0];
        }
        for(int i = 1; i < str1.size(); i++) for(int j = 1; j < str2.size(); j++){
            if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
        return dp.back().back();
    }
};


//    a  c  e
// a  1  1  1
// b     
// c
// d
// e

//    y  b  y
// b  0. 1. 1
// l  0. 1. 1

