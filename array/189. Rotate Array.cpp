class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> head;
        k = k % nums.size();
        for(int i = nums.size()-k; i < nums.size(); i++) head.push_back(nums[i]);
        for(int i = nums.size()-1; i > k-1; i--) nums[i] = nums[i-k];
        for(int i = 0; i < k; i++) nums[i] = head[i];
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};