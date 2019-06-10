class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> result(nums.size(), "");
        map<int, int> scoreToIndex;
        for(int i = 0; i < nums.size(); i++) scoreToIndex[nums[i]] = i;
        int counter = 0;
        for(map<int, int>::reverse_iterator itor = scoreToIndex.rbegin(); itor != scoreToIndex.rend(); itor++){
            if(counter++ < 3){
                if(counter == 1) result[itor->second] = "Gold Medal";
                if(counter == 2) result[itor->second] = "Silver Medal";
                if(counter == 3) result[itor->second] = "Bronze Medal";
            }
            else{
                result[itor->second] = to_string(counter);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> s2i;
        for(int i = 0; i < nums.size(); i++) s2i[nums[i]] = i;
        vector<string> ans(nums.size());
        int r = nums.size();
        for(auto p: s2i){
            if(r == 1) ans[p.second] = "Gold Medal";
            else if(r == 2) ans[p.second] = "Silver Medal";
            else if(r == 3) ans[p.second] = "Bronze Medal";
            else ans[p.second] = to_string(r);
            r--;
        }
        return ans;
    }
};