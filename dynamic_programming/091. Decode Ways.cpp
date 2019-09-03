class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0'? 0: 1;
        for(int i = 2; i < s.size()+1; i++){
            if(s[i-1] > '0') dp[i] = dp[i-1];
            if(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7')
                dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0'? 0: 1;
        for(int i = 2; i < dp.size(); i++){
            if(s[i-1] > '0') dp[i] = dp[i-1];
            if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7') dp[i] += dp[i-2];
        }
        return dp.back();
    }
};

class Solution {
public:
    int numDecodings(string s) {
        vector<long> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0') dp[i+1] += dp[i];
            if(i-1 >= 0 && (s[i-1] == '2' && s[i] <= '6' || s[i-1] == '1')) dp[i+1] += dp[i-1];
        }
        return dp.back();
    }
};