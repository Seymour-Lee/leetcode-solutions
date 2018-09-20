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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0) return {newInterval};
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].start >= newInterval.start){
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
            if(i == intervals.size()-1) intervals.push_back(newInterval);
        }
        vector<Interval> ans;
        for(auto itv: intervals){
            if(ans.size() == 0) {ans.push_back(itv); continue;}
            auto last = ans.back();
            if(last.start == itv.start ||last.end >= itv.start){
                ans.pop_back();
                ans.push_back(Interval(min(last.start, itv.start), max(last.end, itv.end)));
            }
            else{
                ans.push_back(itv);
            }
        }
        return ans;
    }
};