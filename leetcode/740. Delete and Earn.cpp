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