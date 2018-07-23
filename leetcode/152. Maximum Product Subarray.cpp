class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int result = nums[0];
        int maxs = nums[0];
        int mins = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int last_max = maxs;
            maxs = max(max(maxs*nums[i], nums[i]), mins*nums[i]);
            mins = min(min(last_max*nums[i], nums[i]), mins*nums[i]);
            result = max(result, maxs);
        }
        return result;
    }
};