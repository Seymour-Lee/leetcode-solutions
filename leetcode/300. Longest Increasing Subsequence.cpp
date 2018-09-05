class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            int largest = 0;
            for(int j = 0; j < i; j++) 
                if(nums[i] > nums[j])
                    largest = max(largest, dp[j]);
            dp[i] = largest+1;
        }
        int result = 0;
        for(auto d: dp) result = max(result, d);
        return result;
    }
};