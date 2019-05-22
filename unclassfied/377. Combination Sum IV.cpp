class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        for(int i = 1; i < dp.size(); i++){
            for(auto num: nums){
                dp[i] += i - num > 0? dp[i-num]: i-num == 0? 1: 0;
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto num: nums){
                dp[i] += (i-num >= 0? dp[i-num]: 0);
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto num: nums) if(i-num >= 0) dp[i] += dp[i-num];
        }
        return dp[target];
    }
};