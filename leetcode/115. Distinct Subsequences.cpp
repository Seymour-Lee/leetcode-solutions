class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int j = 0; j <= n; j++) dp[0][j] = 1;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1]? dp[i-1][j-1]: 0);
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < dp.size(); i++) dp[i][0] = 1;
        for(int j = 1; j <= n; j++){
            for(int i = j; i <= m; i++){
                dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1]? dp[i-1][j-1]: 0);
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        long long m = s.size(), n = t.size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for(long long i = 0; i < dp.size(); i++) dp[i][0] = 1;
        for(long long j = 1; j <= n; j++){
            for(long long i = j; i <= m; i++){
                dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1]? dp[i-1][j-1]: 0);
            }
        }
        return dp.back().back();
    }
};