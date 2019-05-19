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

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        return lcs(s, t);
    }
    
private:
    int lcs(string s, string t){
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = string(s.rbegin(), s.rend());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        dp[0][0] = (s[0] == r[0]);
        for(int i = 1; i < s.size(); i++) if(s[i] == r[0]) dp[i][0] = 1; else dp[i][0] = dp[i-1][0];
        for(int j = 1; j < r.size(); j++) if(s[0] == r[j]) dp[0][j] = 1; else dp[0][j] = dp[0][j-1];
        for(int i = 1; i < s.size(); i++){
            for(int j = 1; j < r.size(); j++){
                if(s[i] == r[j]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for(int len = 2; len <= s.size(); len++) {
            for(int i = 0, j = i+len-1; j < s.size(); i++, j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp.front().back();
    }
};

//  bbbab
//  [i][j] = the longest palindromic subseq from index i to j
//      =>  dp[i][j] = if(s[i] == s[j]) dp[i+1][j-1]+2;
//                     else             max(dp[i+1][j], dp[i][j-1]);
//      =>  init: dp[i][i] = 1
//      0   1   2   3   4
//  0   1   
//  1       1
//  2
//  3
//  4