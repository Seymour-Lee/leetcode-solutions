class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        int ans = 0;
        int longest = *max_element(dp.begin(), dp.end());
        for(int i = 0; i < count.size(); i++) 
            if(dp[i] == longest) ans += count[i];
        return ans;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        int ans = 0;
        int longest = *max_element(dp.begin(), dp.end());
        for(int i = 0; i < count.size(); i++) 
            if(dp[i] == longest) ans += count[i];
        return ans;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }
        int ans = 0;
        int longest = *max_element(dp.begin(), dp.end());
        for(int i = 0; i < count.size(); i++) 
            if(dp[i] == longest) ans += count[i];
        return ans;
    }
};