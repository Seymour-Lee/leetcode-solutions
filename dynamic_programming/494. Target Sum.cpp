class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        backtracking(nums, S, 0, 0, ans);
        return ans;
    }
    
private:
    void backtracking(vector<int> &nums, int s, int sum, int pos, int &ans){
        if(pos == nums.size()){
            if(s == sum){
                ans++;
            }
            return;
        }
        backtracking(nums, s, sum+nums[pos], pos+1, ans);
        backtracking(nums, s, sum-nums[pos], pos+1, ans);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        backtracking(nums, 0, 0, S, ans);
        return ans;
    }
    
private:
    void backtracking(vector<int> &nums, int pos, int sum, int target, int &ans){
        if(pos == nums.size()){
            if(sum == target) ans++;
            return;
        }
        backtracking(nums, pos+1, sum+nums[pos], target, ans);
        backtracking(nums, pos+1, sum-nums[pos], target, ans);
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> sum2num;
        sum2num[0] = 1;
        for(auto x: nums){
            auto prev = sum2num;
            sum2num.clear();
            for(auto p: prev){
                sum2num[p.first+x] += p.second;
                sum2num[p.first-x] += p.second;
            }
        }
        return sum2num[S];
    }
};