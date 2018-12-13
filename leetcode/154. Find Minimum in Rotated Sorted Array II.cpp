class Solution { // contain duplicates
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int l = 0, r = nums.size()-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] < nums[r]) r = m;
            else if(nums[m] > nums[r]) l = m+1;
            else r--;
        }
        return nums[l];
    }
};