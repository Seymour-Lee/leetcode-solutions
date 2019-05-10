// TLE
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size() < 7) return false;
        vector<int> sums(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i++) sums[i] = sums[i-1] + nums[i];
        for(int i = 1; i < nums.size()-5; i++){
            for(int j = i+2; j < nums.size()-3; j++){
                for(int k = j+2; k < nums.size()-1; k++){
                    if(sums[i-1] == sums[j-1]-sums[i] && 
                       sums[j-1]-sums[i] == sums[k-1]-sums[j] && 
                       sums[k-1]-sums[j] == sums.back()-sums[k]) return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size() < 7) return false;
        vector<int> sums(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i++) sums[i] = sums[i-1] + nums[i];
        for(int j = 3; j < nums.size()-3; j++){
            set<int> memo = {};
            for(int i = 1; i < j - 1; i++){
                if(sums[i-1] == sums[j-1]-sums[i])
                    memo.insert(sums[i-1]);
            }
            for(int k = j+2; k < nums.size()-1; k++){
                if(sums.back()-sums[k] == sums[k-1]-sums[j] && 
                   memo.find(sums[k-1]-sums[j]) != memo.end())
                    return true;
            }
        }
        return false;
    }
};