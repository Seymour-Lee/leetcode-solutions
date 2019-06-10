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

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin()+k, 0);
        double ans = sum;
        for(int i = k; i < nums.size(); i++){
            sum = sum + nums[i] - nums[i-k];
            ans = max(ans, sum);
        }
        return ans / k;
    }
};