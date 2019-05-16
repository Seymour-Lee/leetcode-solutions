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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.find(target-nums[i]) != seen.end()) 
                return {seen[target-nums[i]], i};
            seen[nums[i]] = i;
        }
        return {-1, -1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        for(int i = 0; i < nums.size(); i++){
            if(num2idx.find(target-nums[i]) != num2idx.end()) return {num2idx[target-nums[i]], i};
            num2idx[nums[i]] = i;
        } 
        return {-1, -1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        for(int i = 0; i < nums.size(); i++){
            if(num2idx.find(target-nums[i]) != num2idx.end()) return {num2idx[target-nums[i]], i};
            num2idx[nums[i]] = i;
        }
        return {-1, -1};
    }
};