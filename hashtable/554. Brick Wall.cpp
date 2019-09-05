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

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        for(auto &r: wall) for(int i = 1; i < r.size(); i++) r[i] += r[i-1];
        int ans = 0;
        // for(auto r: wall){
        //     for(auto e: r) cout<<e<<" ";
        //     cout<<endl;
        // }
        unordered_map<int, int> s2c;
        for(auto r: wall) for(int i = 0; i < r.size()-1; i++) s2c[r[i]]++;
        for(auto p: s2c) ans = max(ans, p.second);
        return wall.size()-ans;
    }
};