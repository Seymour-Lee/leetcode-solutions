class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            backtracking(nums, ans, i+1, vector<int>{nums[i]});
        }
        for(auto vec: ans) result.push_back(vec);
        return result;
    }
    
private:
    void backtracking(vector<int> &nums, set<vector<int>> &ans, 
                      int pos, vector<int> cur){
        if(pos == nums.size()){
            if(cur.size() > 1) ans.insert(cur);
            return;
        }
        if(cur.back() <= nums[pos]){
            backtracking(nums, ans, pos+1, cur);
            cur.push_back(nums[pos]);
            backtracking(nums, ans, pos+1, cur);
        }
        else{
            backtracking(nums, ans, pos+1, cur);
        }
    }
};

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            vector<int> cur;
            backtracking(nums, ans, i, cur);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
private:
    void backtracking(vector<int> &nums, set<vector<int>> &ans, int pos, vector<int> &cur){
        if(pos == nums.size()) return;
        if(cur.empty() || cur.back() <= nums[pos]){
            cur.push_back(nums[pos]);
            if(cur.size() >= 2) ans.insert(cur);
            backtracking(nums, ans, pos+1, cur);
            cur.pop_back();
        }
        backtracking(nums, ans, pos+1, cur);
    }
};