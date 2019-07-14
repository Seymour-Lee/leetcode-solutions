class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        unordered_map<int, int> a2t;
        for(auto num: nums) a2t[num]++;
        int most = nums.size() / K;
        for(auto p: a2t) if(p.second > most) return false;
        return true;
    }
};