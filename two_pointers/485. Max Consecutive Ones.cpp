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

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0, j = 0;
        while(i < nums.size() && nums[i] == 0) i++;
        j = i;
        while(i <= j && j < nums.size()){
            if(nums[j] == 1) j++;
            else{
                ans = max(ans, j-i);
                while(j < nums.size() && nums[j] == 0) j++;
                i = j;
            }
        }
        return max(ans, j-i);
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        for(int i = 0, j = 0; i <= j && j < nums.size(); j++){
            if(nums[j] == 1){
                if(nums[i] == 0) i = j;
                ans = max(ans, j-i+1);
            }
            else i = j;
        }
        return ans;
    }
};