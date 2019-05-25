class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i = 0; i < nums.size(); i++) result = result ^ i ^ nums[i];
        return result;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++) ans ^= i ^ nums[i];
        return ans;
    }
};