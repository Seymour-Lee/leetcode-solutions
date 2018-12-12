class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        const int r = *max_element(nums.begin(), nums.end());
        vector<int> points(r + 1, 0);
        for(auto num: nums) points[num] += num;
        return rob(points);
    }
    
private:
    int rob(vector<int> nums){
        int dp1 = 0, dp2 = 0;
        for(auto num: nums){
            int dp = max(dp2 + num, dp1);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        const int maxval = *max_element(nums.begin(), nums.end());
        vector<int> houses(maxval+1, 0);
        for(auto num: nums) houses[num] += num;
        vector<int> dp(maxval+1, 0);
        dp[0] = houses[0], dp[1] = houses[1];
        for(int i = 2; i < houses.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+houses[i]);
        }
        return max(dp.back(), dp[maxval+1-2]);
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxval = *max_element(nums.begin(), nums.end());
        vector<int> houses(maxval+1, 0);
        for(auto num: nums) houses[num] += num;
        int odd = 0, even = 0;
        for(int i = 0; i < houses.size(); i++){
            if(i % 2 == 0) even = max(even+houses[i], odd);
            else odd = max(odd+houses[i], even);
        }
        return max(odd, even);
    }
};