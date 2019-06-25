class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size()-1;
        while(m <= r){
            if(nums[m] == 0){
                swap(nums[l], nums[m]);
                l++; m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else if(nums[m] == 2){
                swap(nums[m], nums[r]);
                r--;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, b = nums.size()-1;
        for(int i = 0; i <= b; i++){
            if(nums[i] == 0) swap(nums[r++], nums[i]);
            else if(nums[i] == 2) swap(nums[b--], nums[i--]);
        }
    }
};