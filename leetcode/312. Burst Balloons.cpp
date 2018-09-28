class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for(int k = 2; k < nums.size(); k++){
            for(int left = 0; left < nums.size()-k; left++){
                int right = left + k;
                for(int i = left+1; i < right; i++){
                    dp[left][right] = max(dp[left][right],
                        nums[left]*nums[i]*nums[right]+dp[left][i]+dp[i][right]);
                }
            }
        }
        
        return dp[0].back();
    }
};