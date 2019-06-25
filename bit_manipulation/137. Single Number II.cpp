class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        if(nums[0] != nums[1]) return nums[0];
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return nums.back();
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(auto num: nums){
            a = a ^ num & (~b);
            b = b ^ num & (~a);
        }
        return a;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto num: nums){
            ones = (ones ^ num) & (~twos);
            twos = (twos ^ num) & (~ones);
        }
        return ones;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int counter = 0;
            for(auto num: nums) counter += (num >> i) & 1;
            ans |= (counter % 3) << i;
        }
        return ans;
    }
};