class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "" || s.size() == 1) return s;
        vector<vector<bool>> is;
        string result = s.substr(0, 1);
        for(int i = 0; i < s.size(); i++){
            vector<bool> cur = {true};
            is.push_back(cur);
            if(i > 0){
                if(s[i] == s[i-1]){
                    is[i-1].push_back(true);
                    result = s.substr(i-1, 2);
                }
                else{
                    is[i-1].push_back(false);
                }
            }
        }
        for(int j = 2; j < s.size(); j++){
            for(int i = 0; i < s.size() - j; i++){
                if(s[i] == s[i+j] && is[i+1][j-2]){
                    is[i].push_back(true);
                    result = s.substr(i, j+1);
                }
                else{
                    is[i].push_back(false);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string ans = string(1, s[0]);
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < dp.size(); i++) dp[i][i] = 1;
        for(int i = 0; i < dp.size()-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 2;
                ans = s.substr(i, 2);
            }
        }
        for(int len = 3; len <= s.size(); len++){
            for(int i = 0; i+len-1 < s.size(); i++){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1] != 0){
                    dp[i][j] = dp[i+1][j-1]+2;
                    if(dp[i][j] > ans.size()) ans = s.substr(i, len);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string ans = string(1, s[0]);
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) dp[i][i] = true;
        for(int i = 0; i < s.size()-1; i++) if(s[i] == s[i+1]) dp[i][i+1] = true, ans = s.substr(i, 2);
        for(int len = 3; len <= s.size(); len++){
            for(int i = 0, j = i+len-1; j < s.size(); i++, j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                if(dp[i][j] && j-i+1 > ans.size()) ans = s.substr(i, j-i+1);
            }
        }
        return ans;
    }
};