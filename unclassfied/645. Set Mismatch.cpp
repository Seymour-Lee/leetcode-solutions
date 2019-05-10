class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int first, second;
        vector<bool> vec(nums.size()+1, false);
        for(int i = 0; i < nums.size(); i++){
            if(vec[nums[i]]){
                first = nums[i];
            }
            vec[nums[i]] = true;
        }
        for(int i = 1; i < vec.size(); i++){
            if(vec[i] == false){
                second = i;
                break;
            }
        }
        return vector<int>{first, second};
    }
};