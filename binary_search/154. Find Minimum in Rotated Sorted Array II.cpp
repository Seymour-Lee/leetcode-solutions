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

class Solution {
public:
    int findMin(vector<int>& nums) {
        int e = nums.size();
        while(e-1 != 0 && nums[0] == nums[e-1]) e--;
        int l = 0, r = e;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] > nums[e-1]) l = m + 1;
            else r--;
        }
        return nums[l];
    }
};