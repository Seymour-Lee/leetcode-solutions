class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int left = 1;
        for(int i = 0; i < nums.size(); i++){
            result[i] *= left;
            left *= nums[i];
        }
        int right = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int l = 1;
        for(int i = 0; i < nums.size(); i++){
            ans[i] = ans[i] * l;
            l = l * nums[i];
        }
        int r = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            ans[i] = ans[i] * r;
            r = r * nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for(int i = 0, l = 1; i < nums.size(); i++) ans[i] = l, l = l*nums[i];
        for(int i = nums.size()-1, r = 1; i >= 0; i--) ans[i] = r*ans[i], r = r*nums[i];
        return ans;
    }
};