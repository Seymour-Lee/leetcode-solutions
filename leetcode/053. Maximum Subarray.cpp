class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sums;
        sums.push_back(nums[0]);
        
        for(int i = 1; i <nums.size(); i++){
            sums.push_back(max(nums[i], nums[i]+sums[i-1]));
        }
        
        int result = INT_MIN;
        for(int i = 0; i < sums.size(); i++)
            result = max(result, sums[i]);
        
        return result;
    }
};