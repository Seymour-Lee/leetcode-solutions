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

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        vector<int> l(nums.size(), nums[0]), r(nums.size(), nums.back());
        for(int i = 1; i < nums.size(); i++) l[i] = l[i-1]+nums[i];
        for(int i = nums.size()-2; i >= 0; i--) r[i] = r[i+1]+nums[i];
        for(int i = 0; i < l.size(); i++) if(l[i] == r[i]) return i;
        return -1;
    }
};