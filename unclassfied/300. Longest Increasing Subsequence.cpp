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

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> seq;
        for(auto num: nums){
            auto itor = lower_bound(seq.begin(), seq.end(), num);
            if(itor == seq.end()) seq.push_back(num);
            else *itor = num;
        }
        return seq.size();
    }
};