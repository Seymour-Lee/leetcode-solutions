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

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        string ans = string(1, s[0]);
        for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for(int i = 0; i < s.size()-1; i++) if(s[i] == s[i+1]) ans = s.substr(i, 2), dp[i][i+1] = 2;
        for(int len = 3; len <= s.size(); len++){
            for(int i = 0, j = i+len-1; j < s.size(); i++, j++) if(dp[i+1][j-1] != 0){
                dp[i][j] = s[i] == s[j]? dp[i+1][j-1]+2: 0;
                if(dp[i][j] != 0) ans = s.substr(i, len);
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string ans = "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) dp[i][i] = true, ans = s.substr(i, 1);
        for(int i = 0; i+2-1 < s.size(); i++) if(s[i] == s[i+1]) dp[i][i+1] = true, ans = s.substr(i, 2);
        for(int len = 3; len <= s.size(); len++){
            for(int i = 0, j = i+len-1 ; j < s.size(); i++, j++){
                if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true, ans = s.substr(i, len);
            }
        }
        return ans;
    }
};

// "babad", size() == 5
// dp[i][j] represents whether s[i:j+1] is palindromic or not
//      0   1   2   3   4
//  0   T
//  1       T
//  2           T
//  3               T
//  4                   T

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int pos = 0; pos < s.size(); pos++){
            int i = pos, j = pos;
            while(i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
            if(j-i-1 > ans.size()) ans = s.substr(i+1, j-i-1);
            i = pos, j = pos+1;
            while(i >= 0 && j < s.size() && s[i] == s[j]) i--, j++;
            if(j-i-1 > ans.size()) ans = s.substr(i+1, j-i-1);
        }
        return ans;
    }
};