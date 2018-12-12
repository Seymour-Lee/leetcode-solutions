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
        if(intervals.size() == 0) return true;
        auto f = [](Interval a, Interval b){return a.start < b.start;};
        sort(intervals.begin(), intervals.end(), f);
        int pend = intervals[0].end;
        for(decltype(intervals.size()) i = 1; i < intervals.size(); i++){
            if(intervals[i].start < pend) return false;
            pend = intervals[i].end;
        }
        return true;
    }
};

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
        vector<pair<int, bool>> itvs;
        for(auto e: intervals){
            itvs.push_back({e.start, true});
            itvs.push_back({e.end, false});
        }
        auto f = [](pair<int, bool> a, pair<int, bool> b){return a.first < b.first;};
        sort(itvs.begin(), itvs.end());
        int counter = 0;
        for(auto itv: itvs){
            counter += itv.second? 1: -1;
            if(counter > 1) return false;
        }
        return true;
    }
};