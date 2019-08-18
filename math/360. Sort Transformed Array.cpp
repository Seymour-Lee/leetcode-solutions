class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if(a == 0){
            for(auto &num: nums) num = num*b+c;
            if(b < 0) reverse(nums.begin(), nums.end());
            return nums;
        }
        double mid = -(double)b / (2*a);
        vector<int> ans;
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int far = fabs((double)nums[i]-mid) >= fabs((double)nums[j]-mid)? 
                                                        nums[i++]: nums[j--];
            ans.push_back(far);
        }
        for(auto &x: ans) x = a*x*x+b*x+c;
        if(a > 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if(a == 0){
            for(auto &num: nums) num = num*b+c;
            if(b < 0) reverse(nums.begin(), nums.end());
            return nums;
        }
        double mid = -(double)b / (2*a);
        vector<int> ans;
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int far = fabs((double)nums[i]-mid) >= fabs((double)nums[j]-mid)? 
                                                        nums[i++]: nums[j--];
            ans.push_back(far);
        }
        for(auto &x: ans) x = a*x*x+b*x+c;
        if(a > 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};