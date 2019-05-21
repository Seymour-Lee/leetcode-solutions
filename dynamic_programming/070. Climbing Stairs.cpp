class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways = {1, 2};
        for(int i = 2; i < n; i++){
            ways.push_back(ways[i-1] + ways[i-2]);
        }
        return ways[n-1];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int ans = 1;
        int prev2 = 1, prev1 = 1;
        for(int i = 2; i <= n; i++){
            ans = prev1 + prev2;
            prev2 = prev1, prev1 = ans;
        }
        return ans;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};