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