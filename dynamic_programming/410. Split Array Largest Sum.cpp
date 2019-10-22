class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long>> dp(n+1, vector<long>(m+1, INT_MAX)); dp[0][0] = 0;
        // dp[i][j] represents [0...i] with j parts
        vector<long> subs(n+1, 0);
        for(int i = 0; i < nums.size(); i++) subs[i+1] = subs[i]+nums[i];
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
            for(int k = 0; k < i; k++){
                dp[i][j] = min(dp[i][j], max(dp[k][j-1], subs[i]-subs[k]));
            }
        }
        
        return dp[n][m];
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long>> dp(nums.size()+1, vector<long>(m+1, INT_MAX));
        dp[0][0] = 0;
        vector<long> sums(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++) sums[i+1] = sums[i] + nums[i];
        for(int i = 1; i <= nums.size(); i++) for(int j = 1; j <= m; j++){
            for(int k = 0; k < i; k++){
                dp[i][j] = min(dp[i][j], max(dp[k][j-1], sums[i]-sums[k]));
            }
        }
        return dp.back().back();
    }
};