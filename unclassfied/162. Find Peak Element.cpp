class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1])
                return i;
        }
        return nums.size()-1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(i == 0 && nums[i] > nums[i+1]) return i;
            else if(nums[i-1] < nums[i] && nums[i] > nums[i+1])
                return i;
        }
        return nums.size()-1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] > nums[m+1]) r = m;
            else l = m+1; // [m] <= [m+1]
        }
        return l;
    }
};