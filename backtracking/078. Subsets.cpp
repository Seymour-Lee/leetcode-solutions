class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        dfs(result, cur, nums, 0);
        return result;
    }
    
private:
    void dfs(vector<vector<int>> &result, vector<int> cur, vector<int> nums, int idx){
        result.push_back(cur);
        for(int i = idx; i < nums.size(); i++){
            cur.push_back(nums[i]);
            dfs(result, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums, ans, 0, {});
        return ans;
    }
    
private:
    void backtracking(vector<int> &nums, vector<vector<int>> &ans, int pos, vector<int> cur){
        if(pos == nums.size()){
            ans.push_back(cur);
            return;
        }
        backtracking(nums, ans, pos+1, cur);
        cur.push_back(nums[pos]);
        backtracking(nums, ans, pos+1, cur);
    }
};