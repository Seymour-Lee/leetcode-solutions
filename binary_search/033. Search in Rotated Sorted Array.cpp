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

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < nums[l]){
                if(nums[m] < target && target <= nums[r]) l = m+1;
                else r = m-1;
            }
            else if(nums[m] > nums[r]){
                if(nums[l] <= target && target < nums[m]) r = m-1;
                else l = m+1;
            }
            else{
                if(target < nums[m]) r = m-1;
                else l = m+1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = pivot(nums);
        int a = binary(nums, 0, pos+1, target);
        if(a != -1) return a;
        int b = binary(nums, pos+1, nums.size(), target);
        return b;
    }
    
private:
    int binary(vector<int> &nums, int l, int r, int target){
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) l = m + 1;
            else r = m;
        }
        return -1;
    }
    
    int pivot(vector<int> &nums){
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(m-1 >= 0 && nums[m-1] < nums[m] && m+1 < nums.size() && nums[m] > nums[m+1]) return m;
            if(m-1 < 0 && m+1 < nums.size() && nums[m] > nums[m+1]) return m;
            if(m-1 >= 0 && nums[m-1] < nums[m] && m+1 >= nums.size()) return m;
            if(nums[l] < nums[m]) l = m+1;
            else r--;
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] >= nums[0]) l++;
            else r = m;
            //cout<<l<<" "<<r<<endl;
        }
        //cout<<l<<endl;
        int l1 = 0, r1 = l, l2 = l, r2 = nums.size();
        while(l1 < r1){
            int m = l1 + (r1 - l1) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) l1 = m+1;
            else r1 = m;
        }
        while(l2 < r2){
            int m = l2 + (r2 - l2) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target) l2 = m+1;
            else r2 = m;
        }
        return -1;
    }
};