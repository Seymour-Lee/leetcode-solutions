/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() < 2) return 0;
        int ans = 0;
        auto f = [](Interval a, Interval b){
            return (a.start < b.start) || (a.start == b.start && a.end < b.end);
        };
        sort(intervals.begin(), intervals.end(), f);
        auto prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(prev.start == intervals[i].start){
                ans++;
            }
            else if(prev.end > intervals[i].start){
                ans++;
                if(intervals[i].end <= prev.end){
                    prev = intervals[i];
                }
            }
            else{
                prev = intervals[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return 0;
        int ans = 0;
        auto f = [](vector<int> a, vector<int> b){
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        };
        sort(intervals.begin(), intervals.end(), f);
        auto prev = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(prev[0] == intervals[i][0]){
                ans++;
            }
            else if(prev[1] > intervals[i][0]){
                ans++;
                if(intervals[i][1] <= prev[1]){
                    prev = intervals[i];
                }
            }
            else{
                prev = intervals[i];
            }
        }
        return ans;
    }
};