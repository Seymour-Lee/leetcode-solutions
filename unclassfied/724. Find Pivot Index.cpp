class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int result = -1;
        int left = 0;
        int right = 0;
        for(auto num: nums) right += num;
        for(int i = 0; i < nums.size(); i++){
            right = right - nums[i];
            if(left == right){
                result = i;
                break;
            }
            left  = left + nums[i];
        }
        return result;
    }
};