class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int ones = 0;
        map<int, int> ones2idx;
        ones2idx[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            ones += (nums[i] == 1? 1: -1);
            if(ones2idx.find(ones) != ones2idx.end()){
                result = max(result, i - ones2idx[ones]);
            }
            else{
                ones2idx[ones] = i;
            }
        }
        return result;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> a2p = {{0, 0}};
        int ans = 0;
        for(int i = 0, sum = 0; i < nums.size(); i++){
            sum += (nums[i] == 0? -1: 1);
            if(a2p.find(sum) != a2p.end()) ans = max(ans, i-a2p[sum]+1);
            else a2p[sum] = i+1;
        }
        return ans;
    }
};