class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() <= 2) return true;
        int p = -1;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(p != -1) return false;
                p = i;
            }
        }
        return p == -1 || p == nums.size()-2 || p == 0 ||
               nums[p-1] <= nums[p+1] || nums[p] <= nums[p+2];
    }
};