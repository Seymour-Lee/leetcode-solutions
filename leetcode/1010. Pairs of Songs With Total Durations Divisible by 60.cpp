class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remain(60, 0);
        for(auto t: time) remain[t%60]++;
        int ans = remain[0]*(remain[0]-1)/2 + remain[30]*(remain[30]-1)/2;
        for(int i = 1; i <= 29; i++) ans += remain[i]*remain[60-i];
        return ans;
    }
};