class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int result = 0;
        map<int, int> wid2nums;
        int width = 0;
        for(auto b: wall[0]) width += b;
        for(auto row: wall){
            int cur = 0;
            for(auto b: row){
                cur += b;
                wid2nums[cur]++;
            }
        }
        wid2nums.erase(width);
        for(auto e: wid2nums){
            result = max(result, e.second);
        }
        return wall.size() - result;
    }
};