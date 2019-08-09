class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int odd = 0, even = 0;
        for(int i = 0; i < nums.size(); i += 2){
            int l = i-1 >= 0? nums[i-1]: 1001;
            int r = i+1 < nums.size()? nums[i+1]: 1001;
            if(nums[i] >= min(l, r)) odd += nums[i]-min(l, r)+1;
        }
        for(int i = 1; i < nums.size(); i += 2){
            int l = i-1 >= 0? nums[i-1]: 1001;
            int r = i+1 < nums.size()? nums[i+1]: 1001;
            if(nums[i] >= min(l, r)) even += nums[i]-min(l, r)+1;
        }
        // cout<<odd<<" "<<even<<endl;
        return min(odd, even);
    }
};

// [2,7,10,9,8,9] 4