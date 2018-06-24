class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> mapping;
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int>::iterator itor = mapping.find(target-nums[i]);
            if(itor!=mapping.end()){
                result.push_back(itor->second);
                result.push_back(i);
                break;
            }
            mapping[nums[i]]=i;
        }
        return result;
    }
};