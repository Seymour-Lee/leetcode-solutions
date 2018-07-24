class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        if(nums.size() == 0) return result;
        if(nums.size() <= 2) return nums;
        sort(nums.begin(), nums.end());
        if(nums[0] != nums[1]) result.push_back(nums[0]);
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) result.push_back(nums[i]);
        }
        if(result.size() == 1) result.push_back(nums.back());
        return result;
    }
};