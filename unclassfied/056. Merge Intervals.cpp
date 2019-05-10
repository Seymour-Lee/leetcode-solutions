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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        auto cmp = [](Interval a, Interval b){return a.end < b.end;};
        sort(intervals.begin(), intervals.end(), cmp);
        while(intervals.size() > 1){
            Interval a = intervals.back(); intervals.pop_back();
            Interval b = intervals.back(); intervals.pop_back();
            if(a.start <= b.end){
                Interval c(min(b.start, a.start), a.end);
                intervals.push_back(c);
            }
            else{
                result.push_back(a);
                intervals.push_back(b);
            }
        }
        if(intervals.size()) result.push_back(intervals.back());
        return result;
    }
};