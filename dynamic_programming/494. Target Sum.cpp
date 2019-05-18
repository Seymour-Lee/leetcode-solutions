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