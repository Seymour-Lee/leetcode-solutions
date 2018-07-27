class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, int> table;
        int result = 0;
        for(auto num: nums) table[num]++;
        if(table.size() == 1) return result;
        map<int, int>::iterator itor = table.begin();
        int prevFirst = itor->first;
        int prevSecond = itor->second;
        for(itor++; itor != table.end(); itor++){
            if(itor->first-1 == prevFirst) result = max(result, itor->second+prevSecond);
            prevFirst = itor->first;
            prevSecond = itor->second;
        }
        return result;
    }
};