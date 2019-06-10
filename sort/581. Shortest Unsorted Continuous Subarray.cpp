class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int i = 0, j = nums.size()-1;
        while(nums[i] == sorted[i]) i++;
        while(nums[j] == sorted[j]) j--;
        return i <= j? j - i + 1: 0;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int i = 0, j = nums.size()-1;
        while(i < nums.size() && nums[i] == sorted[i]) i++;
        while(j >= 0 && nums[j] == sorted[j]) j--;
        return i <= j? j - i + 1: 0;
    }
};