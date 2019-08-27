class Solution {
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++){
            num2idxs[nums[i]].push_back(i);
        }
        srand(time(0));
    }
    
    int pick(int target) {
        if(num2idxs[target].size() == 1) return num2idxs[target].back();
        return num2idxs[target][rand() % num2idxs[target].size()];
    }
    
private:
    map<int, vector<int>> num2idxs;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) a2i[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return a2i[target][(rand()%a2i[target].size())];
    }
    
private:
    unordered_map<int, vector<int>> a2i;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */