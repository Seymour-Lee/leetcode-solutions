class Solution {
public:
    int rob(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2){
                odd = max(odd + nums[i], even);
            }
            else{
                even = max(even + nums[i], odd);
            }
        }
        return max(odd, even);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int even = 0, odd = 0;
        for(decltype(nums.size()) i = 0; i < nums.size(); i++){
            if(i % 2 == 1) odd = max(odd+nums[i], even);
            else even = max(even+nums[i], odd);
        }
        return max(even, odd);
    }
};