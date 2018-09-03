class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] > nums[r]){
                if(target < nums[m] && target >= nums[l]) r = m - 1;
                else l = m + 1;
            }
            else if(nums[m] < nums[l]){
                if(target > nums[m] && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
            else{
                if(target < nums[m]) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};