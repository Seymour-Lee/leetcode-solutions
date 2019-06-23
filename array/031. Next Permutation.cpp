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

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while([](vector<int> &nums) -> bool{
            if(nums.size() <= 1) return false;
            int prev = nums.size()-2;
            while(prev >= 0 && nums[prev] >= nums[prev+1]) prev--;
            if(prev == -1){
                reverse(nums.begin(), nums.end());
                return false;
            }
            reverse(nums.begin()+prev+1, nums.end());
            int next = prev+1;
            while(nums[prev] >= nums[next]) next++;
            swap(nums[prev], nums[next]);
            return true;
        }(nums)) ans.push_back(nums);
        return ans;
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int pos = nums.size()-2;
        while(pos >= 0 && nums[pos] >= nums[pos+1]) pos--;
        reverse(nums.begin()+pos+1, nums.end());
        if(pos < 0) return;
        int end = pos+1;
        while(nums[pos] >= nums[end]) end++;
        swap(nums[pos], nums[end]);
    }
};