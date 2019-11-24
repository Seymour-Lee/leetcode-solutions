class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        vector<int> pre = points[0];
        for(auto cur: points){
            int dx = abs(pre[0]-cur[0]);
            int dy = abs(pre[1]-cur[1]);
            ans += max(dy, dx);
            pre = cur;
        }
        return ans;
    }
};