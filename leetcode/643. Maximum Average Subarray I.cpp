class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int result = INT_MIN;
        int sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        result = sum;
        for(int i = k; i < nums.size(); i++){
            sum = sum + nums[i] - nums[i-k];
            result = max(result, sum);
        }
        return (double)result / k;
    }
};