class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        if(!next_permutation(nums.begin(), nums.end()))
            sort(nums.begin(),nums.end());
    }
};