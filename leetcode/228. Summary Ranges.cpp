class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return vector<string>();
        if(nums.size() == 1) return vector<string>{to_string(nums[0])};
        vector<string> result;
        int i, j;
        for(i = 0, j = 1; i < nums.size() && j < nums.size(); j++){
            if(nums[j-1] + 1 != nums[j]){
                if(i + 1 == j) result.push_back(to_string(nums[i]));
                else result.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
                i = j;
            }
        }
        if(i + 1 == j) result.push_back(to_string(nums[i]));
        else result.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        return result;
    }
};