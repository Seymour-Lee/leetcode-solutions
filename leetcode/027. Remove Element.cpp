class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[cur++] = nums[i];
            }
        }
        
        return cur;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) nums[l++] = nums[i];
        }
        return l;
    }
};