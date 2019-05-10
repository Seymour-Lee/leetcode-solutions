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

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(auto num: nums) diff = diff ^ num;
        diff = diff & (-diff);
        vector<int> ans = {0, 0};
        for(auto num: nums){
            if((num & diff) == 0) ans[0] = ans[0] ^ num;
            else ans[1] = ans[1] ^ num;
        }
        return ans;
    }
};