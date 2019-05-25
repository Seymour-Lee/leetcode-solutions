class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        for(int i = nums.size()-1; i > 0; i--){
            nums[i-1] = nums[i-1] ^ nums[i];
        }
        return nums[0];
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums) ans ^= num;
        return ans;
    }
};