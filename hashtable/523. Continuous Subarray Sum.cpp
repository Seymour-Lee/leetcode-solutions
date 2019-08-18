class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum2idx;
        sum2idx[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(k != 0) sum = sum % k;
            auto itor = sum2idx.find(sum);
            if(itor != sum2idx.end() && (i - itor->second) > 1) return true;
            if(itor == sum2idx.end()) sum2idx[sum] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k == 0){
            for(int i = 0; i < nums.size()-1; i++) if(nums[i] == 0 && nums[i+1] == 0) return true;
            return false;
        }
        vector<int> sums(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++) sums[i+1] = sums[i]+nums[i];
        for(int i = 0; i < sums.size(); i++) for(int j = i+2; j < sums.size(); j++){
            if((sums[j]-sums[i])%k == 0) return true;
        }
        return false;
    }
};