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