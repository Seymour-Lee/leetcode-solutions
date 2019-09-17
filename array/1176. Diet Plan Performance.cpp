class Solution {
public:
    int dietPlanPerformance(vector<int>& c, int k, int lower, int upper) {
        int ans = 0;
        int sum = accumulate(c.begin(), c.begin()+k, 0);
        if(sum > upper) ans++;
        if(sum < lower) ans--;
        for(int i = k; i < c.size(); i++) {
            sum += c[i];
            sum -= c[i-k];
            if(sum > upper) ans++;
            if(sum < lower) ans--;
        }
        return ans;
    }
};