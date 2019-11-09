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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> s2idx;
        vector<int> result;
        int n = intervals.size();
        for(int i = 0; i < n; i++) s2idx[intervals[i].start] = i;
        for(auto in: intervals){
            auto itor = s2idx.lower_bound(in.end);
            if(itor == s2idx.end()) result.push_back(-1);
            else result.push_back(itor->second);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> s2idx;
        vector<int> ans;
        for(int i = 0; i < intervals.size(); i++) s2idx[intervals[i][0]] = i;
        for(auto in: intervals){
            auto itor = s2idx.lower_bound(in[1]);
            if(itor == s2idx.end()) ans.push_back(-1);
            else ans.push_back(itor->second);
        }
        return ans;
    }
};

