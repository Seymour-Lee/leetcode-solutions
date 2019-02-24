class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return true;
        if(n < k) return false;
        int sum = 0;
        for(auto num: nums) sum += num;
        if(sum % k != 0) return false;
        int subset = sum / k;
        vector<int> subsetSum(k, 0);
        vector<bool> taken(n, false);
        subsetSum[0] = nums.back();
        taken.back() = true;
        return recursion(nums, subsetSum, taken, subset, k, n, 0, n-1);
    }
    
private:
    bool recursion(vector<int> &nums, vector<int> &subsetSum, vector<bool> &taken, 
                  int subset, int k, int n, int curIdx, int limitIdx){
        if(subsetSum[curIdx] == subset){
            if(curIdx == k-2) return true;
            return recursion(nums, subsetSum, taken, subset, k, n, curIdx+1, n-1);
        }
        for(int i = limitIdx; i >= 0; i--){
            if(taken[i]) continue;
            int cur = subsetSum[curIdx] + nums[i];
            if(cur <= subset){
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = recursion(nums, subsetSum, taken, subset, k, n, curIdx, i-1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if(nxt) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        int n = nums.size();
        if(n < k) return false;
        int sum = 0;
        for(auto num: nums) sum += num;
        if(sum % k != 0) return false;
        int subsum = sum / k;
        vector<int> subsums(k, 0);
        vector<bool> seen(n, false);
        subsums[0] = nums.back();
        seen.back() = true;
        return recursion(nums, k, subsums, seen, 0, subsum, n-1);
    }
    
private:
    bool recursion(vector<int> &nums, int k, vector<int> &subsums, vector<bool> &seen, int cursub, int subsum, int s){
        if(subsums[cursub] == subsum){
            if(cursub == k-2) return true;
            return recursion(nums, k, subsums, seen, cursub+1, subsum, nums.size()-1);
        }
        for(int i = s; i >= 0; i--) if(seen[i] == false){
            if(subsums[cursub]+nums[i] <= subsum){
                seen[i] = true;
                subsums[cursub] += nums[i];
                bool ans = recursion(nums, k, subsums, seen, cursub, subsum, s-1);
                subsums[cursub] -= nums[i];
                seen[i] = false;
                if(ans) return true;
            }
        }
        return false;
    }
};