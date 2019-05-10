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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> ans;
        map<int, int> timeline;
        for(auto peo: schedule) 
            for(auto slot: peo) 
                timeline[slot.start]++, timeline[slot.end]--;
        int workers = 0;
        for(auto time: timeline){
            workers += time.second;
            if(workers == 0) ans.push_back(Interval(time.first, 0));
            if(workers != 0 && ans.size() != 0 && ans.back().end == 0) 
                ans.back().end = time.first;
        }
        if(ans.empty() == false) ans.pop_back();
        return ans;
    }
};