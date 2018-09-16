class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        set<int> st(nums.begin(), nums.end());
        int prev = INT_MIN;
        int cur = 0;
        for(auto e: st){
            cur = e-1 == prev? cur+1: 1;
            prev = e;
            ans = max(ans, cur);
        }
        return ans;
    }
};