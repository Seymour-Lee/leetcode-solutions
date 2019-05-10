class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int result = INT_MAX;
        vector<int> sum(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i++){
            sum[i] = sum[i-1] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int cur = sum[j] - sum[i] + nums[i];
                if(cur >= s){
                    result = min(result, j - i + 1);
                    break;
                }
            }
        }
        return result == INT_MAX? 0: result;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0, j = 0;
        int cursum = nums[0];
        int ans = cursum >= s? 1: INT_MAX;
        while(i <= j && j < nums.size()){
            if(i == j && cursum > s){
                i++, j++, cursum = nums[i];
                continue;
            }
            if(cursum >= s) ans = min(ans, j-i+1), cursum -= nums[i++];
            else if(cursum < s) cursum += nums[++j];
        }
        return ans == INT_MAX? 0: ans;
    }
};