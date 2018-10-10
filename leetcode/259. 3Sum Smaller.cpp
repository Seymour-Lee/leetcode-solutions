class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size()-2; i++){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < target){
                    ans += r-l;
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size()-2; i++){
            for(int j = i+1; j < nums.size()-1; j++){
                int l = j, r = nums.size()-1; // the value of l is really interesting, very tricky
                while(l < r){
                    int m = (r + l + 1) / 2;
                    if(nums[i]+nums[j]+nums[m] < target) l = m;
                    else r = m-1;
                }
                ans += l-j;
            }
        }
        return ans;
    }
};