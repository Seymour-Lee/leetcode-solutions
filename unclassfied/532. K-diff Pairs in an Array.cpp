class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> s;
        int result = 0;
        int size = nums.size();
        
        for(int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (abs(nums[i] - nums[j]) == k && s.find(nums[i] + nums[j]) == s.end()) {
                    result++;
                    s.insert(nums[i] + nums[j]);
                }
            }
        }
        return result;
    }
};