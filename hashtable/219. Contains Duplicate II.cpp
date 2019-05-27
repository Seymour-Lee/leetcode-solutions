class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        map<int ,vector<int>> numToIndexs;
        for(int i = 0; i < nums.size(); i++){
            map<int ,vector<int>>::iterator itor = numToIndexs.find(nums[i]);
            if(itor != numToIndexs.end()){
                vector<int> vec = itor->second;
                for(auto idx: vec){
                    if(abs(idx-i) <= k) return true;
                }
                itor->second.push_back(i);
            }
            else{
                numToIndexs[nums[i]] = vector<int>{i};
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num2idx;
        for(int i = 0; i < nums.size(); i++){
            if(num2idx.find(nums[i]) != num2idx.end() && i-num2idx[nums[i]] <= k) return true;
            num2idx[nums[i]] = i;
        }
        return false;
    }
};