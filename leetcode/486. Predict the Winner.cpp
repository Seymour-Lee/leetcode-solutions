class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return win(nums, 0, nums.size()-1, 1) >= 0;
    }
    
private:
    int win(vector<int> &nums, int s, int e, int turn){
        if(s == e) return turn * nums[s];
        int left = turn * nums[s] + win(nums, s+1, e, -turn);
        int right = turn * nums[e] + win(nums, s, e-1, -turn);
        return turn * max(turn * left, turn * right);
    }
};