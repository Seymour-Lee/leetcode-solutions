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

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = nums[0];
        int vmax = nums[0], vmin = nums[0];
        for(decltype(nums.size()) i = 1; i < nums.size(); i++){
            auto lmax = vmax;
            vmax = max(max(lmax*nums[i], vmin*nums[i]), nums[i]);
            vmin = min(min(lmax*nums[i], vmin*nums[i]), nums[i]);
            ans = max(ans, vmax);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = nums[0];
        int maxval = nums[0];
        int minval = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int maxprev = maxval, minprev = minval;
            maxval = max({nums[i], minprev*nums[i], maxprev*nums[i]});
            minval = min({nums[i], minprev*nums[i], maxprev*nums[i]});
            ans = max(ans, maxval);
        }
        return ans;
    }
};