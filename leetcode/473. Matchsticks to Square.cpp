class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        map<int, int> num2freq;
        int sum = 0;
        for(auto num: nums){
            sum += num;
            num2freq[num]++;
        }
        if(sum % 4 != 0) return false;
        if(num2freq.upper_bound(sum / 4) != num2freq.end()) return false;       
        auto f = [](int a, int b){return a > b;};
        sort(nums.begin(), nums.end(), f);
        return dfs(nums, vector<int>(4, 0), 0, sum/4);
    }
    
private:
    bool dfs(vector<int> nums, vector<int> sums, int idx, int target){
        if(idx == nums.size()){
            if(sums[0] == target && sums[1] == target && sums[2] == target){
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++){
            if(sums[i] + nums[idx] > target) continue;
            sums[i] += nums[idx];
            if(dfs(nums, sums, idx+1, target)) return true;
            sums[i] -= nums[idx];
        }
        return false;
    }
};