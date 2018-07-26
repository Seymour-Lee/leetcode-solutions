class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(nums.size() == 0 || findNums.size() == 0) return vector<int>();
        map<int, int> dict;
        for(int i = 0; i < nums.size(); i++) dict[nums[i]] = i;
        vector<int> result;
        for(auto num: findNums){
            bool find = false;
            for(int i = dict[num]; i < nums.size(); i++){
                if(nums[i] > num){
                    result.push_back(nums[i]);
                    find = true;
                    break;
                }
            }
            if(find == false) result.push_back(-1);
        }
        return result;
    }
};