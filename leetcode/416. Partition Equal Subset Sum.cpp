class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) return true;
        int sum = 0;
        for(auto num: nums) sum += num;
        if(sum % 2 == 1) return false;
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        dp[0][0] = true;
        for(int i = 1; i < n+1; i++) dp[i][0] = true;
        for(int j = 1; j < sum+1; j++) dp[0][j] = false;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]){
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }
        return dp[n][sum];
    }
};