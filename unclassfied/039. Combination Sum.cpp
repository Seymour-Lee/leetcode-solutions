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