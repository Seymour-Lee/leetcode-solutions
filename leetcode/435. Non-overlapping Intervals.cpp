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