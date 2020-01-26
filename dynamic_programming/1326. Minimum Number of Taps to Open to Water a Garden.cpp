class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for(int i = 0; i <= n; i++){
            if(ranges[i] != 0) intervals.push_back({i-ranges[i], i+ranges[i]});
        }
        return videoStitching(intervals, n);
    }
    
    int videoStitching(vector<vector<int>>& clips, int T) {
        // auto f = [](vector<int> a, vector<int> b){
        //     return a[0] == b[0]? a[1] > b[1]: a[0] < b[0];
        // };
        // sort(clips.begin(), clips.end(), f);
        // int ans = 0, end = 0, covered = 0;
        // for(auto c: clips){
        //     if(covered >= T) break;
        //     if(c[0] > covered) return -1;
        //     if(c[0] >= end) ans++, end = c[1];
        //     covered = max(covered, c[1]);
        // }
        // if(end < T && covered >= T) ans++;
        // return covered >= T? ans: -1;
        sort(begin(clips), end(clips));
        int res = 0;
        for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
            for (; i < clips.size() && clips[i][0] <= st; ++i)
                end = max(end, clips[i][1]);
            if (st == end) return -1;
        }
        return res;
    }
};