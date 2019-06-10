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

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto a: nums) ans += a-minval;
        return ans;
    }
};