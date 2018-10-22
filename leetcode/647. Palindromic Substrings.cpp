class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 0) return 0;
        vector<int> sums = {1};
        int result = 1;
        for(int i = 1; i < s.size(); i++){
            sums.push_back(1);
            for(int j = i - 1; j >= 0; j--){
                if(isPalindromic(s.substr(j, i-j+1))){
                    sums[i]++;
                }
            }
            result += sums.back();
        }
        return result;
    }
    
private:
    bool isPalindromic(string s){
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() <= 1) return s.size();
        int ans = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); i++) dp[i][i] = true, ans++;
        for(int i = 0; i < s.size()-1; i++) if(s[i] == s[i+1]) dp[i][i+1] = true, ans++;
        for(int len = 3; len <= s.size(); len++){
            for(int i = 0; i+len <= s.size(); i++){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1] == true)
                    dp[i][j] = true, ans++;
            }
        }
        return ans;
    }
};