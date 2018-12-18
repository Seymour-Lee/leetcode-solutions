/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto itor = intervals.lower_bound(Interval(val, val));
        int start = val, end = val;
        if(itor != intervals.begin() && (--itor)->end+1 < val) itor++;
        while(itor != intervals.end() && val-1 <= itor->end && itor->start <= val+1){
            start = min(start, itor->start);
            end = max(end, itor->end);
            itor = intervals.erase(itor);
        }
        intervals.insert(itor, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(intervals.begin(), intervals.end());
    }
    
private:
    struct cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, cmp> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */