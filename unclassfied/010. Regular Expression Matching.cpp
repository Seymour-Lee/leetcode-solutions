class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[s.size()][p.size()] = true;
        for(int i = s.size(); i >= 0; i--){
            for(int j = p.size()-1; j >= 0; j--){
                bool first_match = (i < s.size() && 
                                    (p[j] == s[i] ||
                                     p[j] == '.'));
                if(j+1 < p.size() && p[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                }
                else{
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= p.size(); i++)
            dp[0][i] = p[i-1] == '*' && dp[0][i-2]? true: false;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    if(p[j-2] != s[i-1] && p[j-2] != '.'){
                        dp[i][j] = dp[i][j-2];
                    }
                    else{
                        dp[i][j] = (dp[i][j-2] || dp[i][j-1] || dp[i-1][j]);
                    }
                }
            }
        }
        return dp.back().back();
    }
};