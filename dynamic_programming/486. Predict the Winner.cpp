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

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return minimax(nums, 0, nums.size()-1, 1) >= 0;
    }
    
private:
    int minimax(vector<int> &nums, int s, int e, int turn){
        if(s == e) return turn*nums[e];
        int smax = nums[s] + turn*minimax(nums, s+1, e, -turn);
        int emax = nums[e] + turn*minimax(nums, s, e-1, -turn);
        return turn*max(smax, emax);
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        bool even = (n % 2 == 0);
        for(int i = 0; i < n; i++) dp[i][i] = even? -nums[i]: nums[i];
        for(int len = 2; len <= n; len++){
            for(int i = 0; i+len-1 < n; i++){
                int j = i+len-1;
                if(even){
                    if((j-i+1) % 2 == 1){
                        dp[i][j] = min(-nums[i]+dp[i+1][j], dp[i][j-1]-nums[j]);
                    }
                    else{
                        dp[i][j] = max(nums[i]+dp[i+1][j], dp[i][j-1]+nums[j]);
                    }
                }
                else{
                    if((j-i+1) % 2 == 0){
                        dp[i][j] = min(-nums[i]+dp[i+1][j], dp[i][j-1]-nums[j]);
                    }
                    else{
                        dp[i][j] = max(nums[i]+dp[i+1][j], dp[i][j-1]+nums[j]);
                    }
                }
            }
        }
        return dp.front().back() >= 0;
    }
};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        memo = vector<vector<int>>(nums.size(), vector<int>(nums.size(), INT_MAX));
        return dp(nums, 0, nums.size()-1) >= 0;
    }
    
private:
    vector<vector<int>> memo;
    
    int dp(vector<int> &nums, int i, int j){
        if(i == j) return nums[i];
        if(memo[i][j] != INT_MAX) return memo[i][j];
        int pick_s = nums[i] - dp(nums, i+1, j);
        int pick_e = nums[j] - dp(nums, i, j-1);
        return memo[i][j] = max(pick_s, pick_e);
    }
};