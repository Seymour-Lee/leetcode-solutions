class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        return distance(l, r) > nums.size()/2;
    }
};