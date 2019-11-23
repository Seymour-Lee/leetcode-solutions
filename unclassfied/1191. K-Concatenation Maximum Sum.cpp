class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int a_sum = 0, ans = 0;
        for (auto i = 0, sum = 0; i < min(2, k)*arr.size(); i++) {
            sum = max(sum + arr[i % arr.size()], arr[i % arr.size()]);
            ans = max(ans, sum);
            if (i < arr.size()) a_sum += arr[i];
        }
        while (a_sum > 0 && --k >= 2) ans = (ans + a_sum) % 1000000007;
        return ans;
    }
};