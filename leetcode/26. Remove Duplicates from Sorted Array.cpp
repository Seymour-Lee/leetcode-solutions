class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        
        if(nums.size() == 0){
            return result;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[result] != nums[i]){
                nums[++result] = nums[i];
            }
        }
        
        return result + 1;
    }
};