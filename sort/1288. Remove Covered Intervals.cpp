class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        int maxval = 0;
        sort(intervals.begin(), intervals.end());
        for(auto &a: intervals){
            if(a[1] > maxval) maxval = a[1], ans++;
        }
        return ans;
    }
};