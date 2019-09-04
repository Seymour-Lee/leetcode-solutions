class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
        map<int, int> sum2idx;
        sum2idx[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(sum2idx.find(nums[i]-k) != sum2idx.end())
                ans = max(ans, i-sum2idx[nums[i]-k]);
            if(sum2idx.find(nums[i]) == sum2idx.end()) sum2idx[nums[i]] = i;
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        for(int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];
        unordered_map<int, int> s2i = {{0, -1}};
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s2i.find(nums[i]-k) != s2i.end()) ans = max(ans, i-s2i[nums[i]-k]);
            if(s2i.find(nums[i]) == s2i.end()) s2i[nums[i]] = i;
        }
        return ans;
    }
};