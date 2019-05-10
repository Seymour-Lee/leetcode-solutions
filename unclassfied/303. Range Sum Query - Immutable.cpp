class NumArray {
public:
    NumArray(vector<int> nums) {
        sums.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            sums.push_back(sums.back() + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
    
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

// MLE
class NumArray {
public:
    NumArray(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++){
            vector<int> cur = {nums[i]};
            sums.push_back(cur);
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < nums.size()-i; j++){
                sums[i].push_back(sums[i][j-1] + sums[i+j][0]);
            }
        }
    }
    
    int sumRange(int i, int j) {
        return sums[i][j-i];
    }
    
private:
    vector<vector<int>> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

//MLE
class NumArray {
public:
    NumArray(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) sums[i][i] = nums[i];
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                sums[i][j] = sums[i][j-1] + sums[j][j];
            }
        }
    }
    
    int sumRange(int i, int j) {
        return sums[i][j];
    }
    
private:
    map<int, map<int, int>> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

class NumArray {
public:
    NumArray(vector<int> nums) {
        dp.push_back(0);
        for(decltype(nums.size()) i = 0; i < nums.size(); i++)
            dp.push_back(dp.back() + nums[i]);
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
    
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */