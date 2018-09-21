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