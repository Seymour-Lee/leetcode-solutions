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