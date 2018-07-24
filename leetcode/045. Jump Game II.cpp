class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int reach = nums[0];
        int from = 0;
        int step = 0;
        
        for (int i = 1; i <= reach && i < nums.size(); i++) {
            if (i > from) {
                step++;
                from = reach;
            }
            reach = max(reach, i+nums[i]);
        }
        if (reach < nums.size()-1) return 0;
        return step;
    }
};