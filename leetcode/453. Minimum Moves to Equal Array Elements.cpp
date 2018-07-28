class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int minValue = INT_MAX;
        int result = 0;
        for(auto num: nums) minValue = min(num, minValue);
        for(auto num: nums) result += num - minValue;
        return result;
    }
};