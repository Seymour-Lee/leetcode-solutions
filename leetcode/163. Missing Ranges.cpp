class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if((long)lower > (long)upper) return {};
        if(nums.size() == 0) return lower == upper? vector<string>{to_string(lower)}
                                    : vector<string>{to_string(lower)+"->"+to_string(upper)};
        vector<string> ans;
        if(nums[0] != lower){
            if(nums[0]-lower == 1) ans.push_back(to_string(lower));
            else ans.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        for(int i = 0; i < nums.size()-1; i++){
            if((long)nums[i+1]-nums[i] == 2) ans.push_back(to_string(nums[i]+1));
            else if((long)nums[i+1]-nums[i] > 2) 
                ans.push_back(to_string(nums[i]+1)+"->"+to_string(nums[i+1]-1));
        }
        if(nums.back() != upper){
            if(upper-nums.back() == 1) ans.push_back(to_string(upper));
            else ans.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
        }
        return ans;
    }
};