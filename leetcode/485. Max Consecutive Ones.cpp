class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int counter = 0;
        for(auto num: nums){
            if(num == 0){
                result = max(result, counter);
                counter = 0;
            }
            else{
                counter++;
            }
        }
        
        return max(result, counter);
    }
};