class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<multiset<int>> st;
        backtracking(st, nums, 0, multiset<int>{});
        for(auto sub: st){
            vector<int> cur = {};
            for(auto e: sub){
                cur.push_back(e);
            }
            result.push_back(cur);
        }
        return result;
    }
    
private:
    void backtracking(set<multiset<int>> &st, vector<int> &nums, int pos,
                      multiset<int> cur){
        if(pos == nums.size()){
            st.insert(cur);
            return;
        }
        backtracking(st, nums, pos+1, cur);
        cur.insert(nums[pos]);
        backtracking(st, nums, pos+1, cur);
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        backtracking(nums, ans, 0, {});
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
private:
    void backtracking(vector<int> &nums, set<vector<int>> &ans, int pos, vector<int> cur){
        if(pos == nums.size()){
            ans.insert(cur);
            return;
        }
        backtracking(nums, ans, pos+1, cur);
        cur.push_back(nums[pos]);
        backtracking(nums, ans, pos+1, cur);
    }
};