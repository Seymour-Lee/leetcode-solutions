class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> blooming;
        int day = 0;
        for(auto f: flowers){
            day++;
            blooming.insert(f);
            auto lower = prev(blooming.lower_bound(f));
            auto upper = blooming.upper_bound(f);
            if(lower != blooming.end() && f-*lower -1 == k ||
               upper != blooming.end() && *upper-f-1 == k){
                return day;
            }
        }
        return -1;
    }
};