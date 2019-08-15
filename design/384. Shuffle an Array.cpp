class Solution {
public:
    Solution(vector<int> nums) {
        ori = nums;
        cur = nums;
        srand((unsigned)time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        cur = ori;
        return cur;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < cur.size(); i++){
            int idx = rand() % cur.size();
            swap(cur[i], cur[idx]);
        }
        return cur;
    }
    
private:
    vector<int> ori;
    vector<int> cur;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto r = [](int l, int r){
            return l + rand()%(r-l);
        };
        vector<int> ans = nums;
        for(int i = 0; i < ans.size(); i++) swap(ans[i], ans[r(i, ans.size())]);
        return ans;
    }
    
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */