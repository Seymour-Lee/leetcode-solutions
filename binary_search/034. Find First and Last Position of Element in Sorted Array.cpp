class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int l = 0, r = nums.size()-1;
        int m;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] == target) break;
            if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        if(l > r) return {-1, -1};
        l = m, r = m;
        while(l > 0 && nums[l-1] == target) l--;
        while(r < nums.size()-1 && nums[r+1] == target) r++;
        return {l, r};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target);
        if(lower == upper) return {-1, -1};
        return {lower, upper-1};
    }
    
private:
    int lower_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    int upper_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] <= target) l = m + 1;
            else r = m;
        }
        return l;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l1 = 0, r1 = nums.size();
        while(l1 < r1){
            int m = l1 + (r1 - l1) / 2;
            if(nums[m] < target) l1 = m+1;
            else r1 = m;
        }
        int l2 = 0, r2 = nums.size();
        while(l2 < r2){
            int m = l2 + (r2 - l2) / 2;
            if(nums[m] <= target) l2 = m+1;
            else r2 = m;
        }
        return l1 == l2? vector<int>{-1, -1}: vector<int>{l1, l2-1};
    }
};