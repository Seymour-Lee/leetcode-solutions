class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4) != 0;
    }
};

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
        if(n <= 3) return true;
        vector<bool> dp(n+1, false);
        dp[1] = dp[2] = dp[3] = true;
        for(int i = 4; i <= n; i++){
            dp[i] = !(dp[i-1]&&dp[i-2]&&dp[i-3]);
        }
        return dp[n];
    }
};

// TLE
class Solution {
public:
    bool canWinNim(int n) {
        if(n <= 3) return true;
        vector<bool> dp(n+1, false);
        dp[1] = dp[2] = dp[3] = true;
        for(int i = 4; i <= n; i++) dp[i] = !(dp[i-1]&&dp[i-2]&&dp[i-3]);
        return dp[n];
    }
};