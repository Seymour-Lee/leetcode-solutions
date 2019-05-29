class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i+=2){
            result += nums[i];
        }
        return result;
    }
};

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2) ans += nums[i];
        return ans;
    }
};