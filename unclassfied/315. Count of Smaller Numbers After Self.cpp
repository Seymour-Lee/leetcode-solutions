class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<int> ans(nums.size(), 0);
        multiset<int> seen;
        seen.insert(nums.back());
        for(int i = nums.size()-2; i >= 0; i--){
            auto lo = seen.lower_bound(nums[i]);
            ans[i] = distance(seen.begin(), lo);
            seen.insert(nums[i]);
        }
        return ans;
    }
};