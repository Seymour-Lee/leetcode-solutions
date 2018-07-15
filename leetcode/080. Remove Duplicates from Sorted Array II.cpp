class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        
        int result = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[result - 2]){
                nums[result] = nums[i];
                result++;
            }
        }
        
        return result;
    }
};