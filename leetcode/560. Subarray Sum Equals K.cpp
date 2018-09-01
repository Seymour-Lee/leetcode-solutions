class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        int result = 0;
        vector<int> sums(nums.size()+1, 0);
        for(decltype(sums.size()) i = 1; i != sums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
        for(decltype(sums.size()) i = 0; i != sums.size()-1; i++){
            for(decltype(sums.size()) j = i+1; j != sums.size(); j++){
                if(sums[j] - sums[i] == k) result++;
            }
        }
        return result;
    }
};