class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> win;
        for(int i = 0; i < nums.size(); i++){
            if(i > k) win.erase(nums[i-k-1]);
            auto pos = win.lower_bound((long long)nums[i] - (long long)t);
            if(pos != win.end() && 
               labs((long long)*pos-(long long)nums[i]) <= t) return true;
            win.insert(nums[i]);
        }
        return false;
    }
};