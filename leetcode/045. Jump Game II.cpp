class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        int farest = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i+nums[i] >= nums.size()-1) return dp[i]+1;
            for(int j = farest+1; j <= nums[i]+i; j++){
                dp[j] = dp[i]+1;
            }
            farest = max(farest, i+nums[i]);
        }
        return dp.back();
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int reach = nums[0];
        int from = 0;
        int step = 0;
        
        for (int i = 1; i <= reach && i < nums.size(); i++) {
            if (i > from) {
                step++;
                from = reach;
            }
            reach = max(reach, i+nums[i]);
        }
        if (reach < nums.size()-1) return 0;
        return step;
    }
};

// TLE
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= nums[i] && i+j < nums.size(); j++){
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        return dp.back();
    }
};