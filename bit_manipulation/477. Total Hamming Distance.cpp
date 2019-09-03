class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int pos = 0;
        for(int i = 0; i < 31; i++){
            auto f = [i](int a, int b){return a + ((b & (1 << i)? 1: 0));};
            int sum = accumulate(nums.begin(), nums.end(), 0, f);
            result += sum * (nums.size() - sum);
        }
        return result;
    }
};

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int ones = 0, zeros = 0;
            for(auto num: nums){
                if((num >> i) & 1) ones++;
                else zeros++;
            }
            ans += ones*zeros;
        }
        return ans;
    }
};