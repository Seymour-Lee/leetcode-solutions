class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        if(!next_permutation(nums.begin(), nums.end()))
            sort(nums.begin(),nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int prev = nums.size()-2;
        while(prev >= 0 && nums[prev] >= nums[prev+1]) prev--;
        if(prev == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin()+prev+1, nums.end());
        int next = prev+1;
        while(nums[prev] >= nums[next]) next++;
        swap(nums[prev], nums[next]);
    }
};