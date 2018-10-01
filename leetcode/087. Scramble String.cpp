// This is a wrong answer
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() == 1 && s1 == s2) return true;
        vector<bool> dpl2r(s1.size(), false), dpr2l(s1.size(), false);
        vector<int> count(26, 0);
        for(int i = 0; i < s1.size(); i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
            dpl2r[i] = (count == vector<int>(26, 0));
        }
        count = vector<int>(26, 0);
        for(int i = s1.size()-1; i >= 0; i--){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
            dpr2l[i] = (count == vector<int>(26, 0));
        }
        for(int i = 0; i < s1.size()-1; i++){
            if(dpl2r[i] == true && dpr2l[i+1] == true)
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n == 0) return true;
        if(n == 1) return s1 == s2;
        vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(n, vector<bool>(n, false)));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[1][i][j] = (s1[i] == s2[j]);
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                for(int j = 0; j <= n-len; j++){
                    dp[len][i][j] = false;
                    for(int k = 1; k < len && dp[len][i][j] == false; k++){
                        dp[len][i][j] = dp[len][i][j] || 
                            (dp[k][i][j] && dp[len-k][i+k][j+k]) ||
                            (dp[k][i+len-k][j] && dp[len-k][i][j+k]);
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};