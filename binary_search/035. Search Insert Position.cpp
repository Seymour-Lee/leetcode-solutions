class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(target == nums[i]) return i;
            if(target < nums[i]) return i;
        }
        return nums.size();
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        if(nums.back() < target) return nums.size();
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(target < nums[m]) r = m-1;
            else l = m+1;
        }
        return l;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) l = m+1;
            else r = m;
        }
        return l;
    }
};