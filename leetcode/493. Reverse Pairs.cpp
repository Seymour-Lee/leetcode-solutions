// TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int ans = 0;
        map<int, int> num2freq = {{nums.back(), 1}};
        for(int i = nums.size()-2; i >= 0; i--){
            auto upper = num2freq.upper_bound(nums[i]/2);
            // upper = prev(upper);
            // cout<<upper->first<<endl;
            for(auto it = num2freq.begin(); it != upper; it++) ans += ((double)it->first < nums[i]/2.0? it->second: 0);
            // cout<<nums[i]<<" "<<ans<<endl;
            num2freq[nums[i]]++;
        }
        return ans;
    }
};