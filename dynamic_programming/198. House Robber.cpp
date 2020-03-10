class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2){
                odd = max(odd + nums[i], even);
            }
            else{
                even = max(even + nums[i], odd);
            }
        }
        return max(odd, even);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int even = 0, odd = 0;
        for(decltype(nums.size()) i = 0; i < nums.size(); i++){
            if(i % 2 == 1) odd = max(odd+nums[i], even);
            else even = max(even+nums[i], odd);
        }
        return max(even, odd);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() < 3) return *max_element(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return max(dp.back(), dp[nums.size()-2]);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() <= 2) return *max_element(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0], dp[1] = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++) dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return max(dp[dp.size()-2], dp[dp.size()-1]);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() <= 2) return *max_element(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0], dp[1] = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++) dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return max(dp[dp.size()-2], dp[dp.size()-1]);
    }
};