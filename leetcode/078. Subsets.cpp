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