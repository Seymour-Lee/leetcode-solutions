class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int result = 10;
        int cur = 9;
        int have = 9;
        while(--n && have > 0){
            cur = cur * have;
            result += cur;
            have--;
        }
        return result;
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 9;
        for(int i = 2, have = 9; i <= n && have > 0; i++, have--){
            dp[i] = dp[i-1]*have;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};