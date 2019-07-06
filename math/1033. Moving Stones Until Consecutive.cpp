class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());
        queue<vector<int>> q;
        q.push(nums);
        int minval = INT_MAX;
        int maxval = (nums[2]-nums[1] > 1? nums[2]-nums[1]-1: 0) + (nums[1]-nums[0] > 1? nums[1]-nums[0]-1: 0);
        int step = 0;
        set<vector<int>> seen;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                vector<int> cur = q.front();
                sort(cur.begin(), cur.end());
                q.pop();
                seen.insert(cur);
                if(cur[2]-cur[1] == 1 && cur[1]-cur[0] == 1){
                    // maxval = max(step, maxval);
                    minval = min(step, minval);
                    return {minval, maxval};
                    continue;
                }
                for(int i = cur[0]+1; i < cur[2]; i++){
                    if(cur[1] == i) continue;
                    if(seen.find({i, cur[1], cur[2]}) == seen.end()) q.push({i, cur[1], cur[2]});
                    if(seen.find({cur[0], cur[1], i}) == seen.end()) q.push({cur[0], cur[1], i});
                }
            }
            step++;
        }
        return {minval, maxval};
    }
    
private:
//     vector<vector<vector<int>>>;
    
//     vector<int> dp(vector<int> nums){
//         sort(nums.begin(), nums.end());
//         if(nums[2]-nums[1] == 1 && nums[1]-nums[0] == 1) return {0, 0};
//         int maxval = 0;
//         int minval = INT_MAX;
//         vector<int> next = nums;
//         for(int i = nums[0]+1; i < nums[2]; i++){
//             if(i == nums[1]) continue;
            
//         }
//         for(int i = nums[2]-1; i > nums[0]; i--){
//             if(i == nums[1]) continue;
            
//         }
//         memo
//     }
};

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = { a, b, c };
        sort(begin(s), end(s));
        if (s[2] - s[0] == 2) return { 0, 0 };
        return { min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2 };
    }
};

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s = { a, b, c };
        sort(begin(s), end(s));
        if (s[2] - s[0] == 2) return { 0, 0 };
        return { min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2 };
    }
};