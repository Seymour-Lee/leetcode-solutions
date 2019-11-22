class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int ans = 0;
        vector<int> nums;
        for(int i = N+1; i > 0; i /= 10) nums.push_back(i%10);
        reverse(nums.begin(), nums.end());
        function<int(int, int)> f = [&f](int m, int n) -> int{
            return n == 0 ? 1 : f(m, n - 1) * (m - n + 1);
        };
        for(int i = 1; i < nums.size(); i++) ans += 9*f(9, i-1);
        unordered_set<int> v;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i > 0? 0: 1; j < nums[i]; j++){
                if(v.find(j) == v.end()) ans += f(9-i, nums.size()-i-1);
            }
            if(v.find(nums[i]) != v.end()) break;
            v.insert(nums[i]);
        }
        return N - ans;
    }
};