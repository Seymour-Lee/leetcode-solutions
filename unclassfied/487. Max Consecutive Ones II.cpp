class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        int pos0 = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) count++;
            else{
                count = i - pos0;
                pos0 = i;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        bool zero = nums[0] == 0;
        for(int i = 1; i < nums.size(); i++) zero = zero || nums[i] == 0, dp[i] = nums[i] == 0? 0: dp[i-1]+1;
        if(zero == false) return nums.size();
        int ans = *max_element(dp.begin(), dp.end())+1;
        for(int j = 0; j < dp.size(); j++){
            if(dp[j] != 0){
                int i = j-dp[j];
                if(i-1 >= 0 && nums[i] == 0){
                    // cout<<i<<" "<<j<<endl;
                    ans = max(ans, dp[i-1]+dp[j]+1);
                }
            }
        }
        return ans;
    }
};
// [0,0]
// [1,0]