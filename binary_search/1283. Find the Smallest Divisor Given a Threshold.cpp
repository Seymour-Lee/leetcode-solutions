class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        while(l < r){
            int m = l + (r - l) / 2;
            int sum = division(nums, m);
            if(sum <= threshold) r = m;
            else l = m + 1;
        }
        return l;
    }
    
private:
    int division(vector<int>& nums, double divisor){
        int ans = 0;
        for(auto &num: nums) ans += ceil((double)num/divisor);
        return ans;
    }
};