// TLE
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        backtracking(ans, candidates, vector<int>{}, target, 0, 0);
        vector<vector<int>> result;
        for(auto res: ans) result.push_back(res);
        return result;
    }
    
private:
    void backtracking(set<vector<int>> &res, vector<int> &candidates,
                      vector<int> cur, int target, int pos, int sum){
        if(sum > target) return;
        if(pos >= candidates.size() && sum == target){
            res.insert(cur); return;}
        if(sum == target){res.insert(cur); return;}
        for(int i = pos; i < candidates.size(); i++){
            backtracking(res, candidates, cur, target, i+1, sum);
            cur.push_back(candidates[i]);
            backtracking(res, candidates, cur, target, i, sum+candidates[i]);
            cur.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        backtracking(ans, candidates, vector<int>{}, target, 0, 0);
        vector<vector<int>> result;
        for(auto res: ans) result.push_back(res);
        return result;
    }
    
private:
    void backtracking(set<vector<int>> &res, vector<int> &candidates,
                      vector<int> cur, int target, int pos, int sum){
        if(sum > target || pos >= candidates.size()) return;
        if(sum == target){res.insert(cur); return;}
        backtracking(res, candidates, cur, target, pos+1, sum);
        cur.push_back(candidates[pos]);
        backtracking(res, candidates, cur, target, pos, sum+candidates[pos]);
        cur.pop_back();
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        backtracking(candidates, ans, target, {}, 0, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
private:
    void backtracking(vector<int> &nums, set<vector<int>> &ans, 
                      int t, vector<int> cur, int pos, int sum){
        if(pos >= nums.size() || sum > t) return;
        if(sum == t) {
            ans.insert(cur);
            return;
        }
        backtracking(nums, ans, t, cur, pos+1, sum);
        cur.push_back(nums[pos]);
        backtracking(nums, ans, t, cur, pos, sum+nums[pos]);
    }
};