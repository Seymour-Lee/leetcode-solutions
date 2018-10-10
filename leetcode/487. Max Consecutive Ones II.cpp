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