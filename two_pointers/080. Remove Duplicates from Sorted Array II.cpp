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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        while(l <= r && r < nums.size()){
            if(l-2 >= 0 && nums[l-2] == nums[r]) r++;
            else nums[l++] = nums[r++];
        }
        return l;
    }
};