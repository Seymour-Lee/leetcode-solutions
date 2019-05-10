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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, bool>> times;
        for(auto e: intervals){
            times.push_back({e.start, true});
            times.push_back({e.end, false});
        }
        auto f = [](pair<int, bool> a, pair<int, bool> b){
            if(a.first != b.first) return a.first < b.first;
            return (int)a.second < (int)b.second;
        };
        sort(times.begin(), times.end(), f);
        int ans = 0;
        int count = 0;
        for(auto p: times){
            if(p.second) count++;
            else count--;
            ans = max(ans, count);
        }
        return ans;
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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, bool>> itvs;
        for(auto e: intervals){
            itvs.push_back({e.start, true});
            itvs.push_back({e.end, false});
        }
        auto f = [](pair<int, bool> a, pair<int, bool> b){return a.first < b.first;};
        sort(itvs.begin(), itvs.end());
        int ans = 0;
        int counter = 0;
        for(auto itv: itvs){
            counter += itv.second? 1: -1;
            ans = max(ans, counter);
        }
        return ans;
    }
};