class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return {};
        vector<int> ans;
        deque<pair<int, int>> val2pos;
        val2pos.push_back({nums[0], 0});
        for(int i = 1; i < min(k, (int)nums.size()); i++){
            while(val2pos.empty() == false && val2pos.back().first <= nums[i]) val2pos.pop_back();
            val2pos.push_back({nums[i], i});
        }
        ans.push_back(val2pos.front().first);
        for(int i = k; i < nums.size(); i++){
            if(val2pos.front().second == i-k) val2pos.pop_front();
            while(val2pos.empty() == false && val2pos.back().first <= nums[i]) val2pos.pop_back();
            val2pos.push_back({nums[i], i});
            ans.push_back(val2pos.front().first);
        }
        return ans;
    }
};