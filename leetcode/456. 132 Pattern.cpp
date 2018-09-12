class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int mini = INT_MAX;
        for(int j = 0; j < nums.size()-1; j++){
            mini = min(mini, nums[j]);
            for(int k = j+1; k < nums.size(); k++){
                if(nums[j] > nums[k] && nums[k] > mini){
                    return true;
                }
            }
        }
        return false;
    }
};