class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        for(int i = 0; i < n; i++)
            if(nums[i] != i+1) return i+1;
        return n+1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> a(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); i++) if(a.find(i) == a.end()) return i;
        return nums.size()+1;
    }
};