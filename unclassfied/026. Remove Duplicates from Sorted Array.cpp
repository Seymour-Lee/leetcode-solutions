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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int ans = 1;
        for(int i = 1; i < nums.size(); i++) if(nums[i] != nums[ans-1]){
            nums[ans++] = nums[i];
        }
        return ans;
    }
};