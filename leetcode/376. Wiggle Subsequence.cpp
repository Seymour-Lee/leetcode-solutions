class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    up[i] = max(up[i], down[j]+1);
                }
                else if(nums[i] < nums[j]){
                    down[i] = max(down[i], up[j]+1);
                }
            }
        }
        return max(up.back(), down.back());
    }
};