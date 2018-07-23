class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int odd0 = 0;
        int even0 = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(i % 2){
                odd0 = max(odd0 + nums[i], even0);
            }
            else{
                even0 = max(even0 + nums[i], odd0);
            }
        }
        int max0 = max(odd0, even0);
        int odd1 = 0;
        int even1 = 0;
        for(int i = 1; i < nums.size(); i++){
            if(i % 2){
                odd1 = max(odd1 + nums[i], even1);
            }
            else{
                even1 = max(even1 + nums[i], odd1);
            }
        }
        int max1 = max(odd1, even1);
        return max(max0, max1);
    }
};