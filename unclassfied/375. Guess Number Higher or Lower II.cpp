class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return recursion(dp, 1, n);
    }
    
private:
    int recursion(vector<vector<int>> &dp, int s, int e){
        if(s >= e) return 0;
        if(dp[s][e] != 0) return dp[s][e];
        int ans = INT_MAX;
        for(int i = s; i <= e; i++){
            int cur = i + max(recursion(dp, s, i-1), recursion(dp, i+1, e));
            ans = min(ans, cur);
        }
        dp[s][e] = ans;
        return ans;
    }
};