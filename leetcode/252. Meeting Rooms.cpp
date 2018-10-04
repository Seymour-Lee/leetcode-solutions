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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return true;
        auto f = [](Interval a, Interval b){return a.start <= b.start;};
        sort(intervals.begin(), intervals.end(), f);
        for(decltype(intervals.size()) i = 0; i < intervals.size()-1; i++){
            if(intervals[i].start == intervals[i+1].start 
               || intervals[i].end > intervals[i+1].start){
                return false;
            }
        }
        return true;
    }
};