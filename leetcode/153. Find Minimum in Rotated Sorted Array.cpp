class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l < r){
            if(nums[l] < nums[r]) return nums[l];
            int m = l + (r - l) / 2;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};