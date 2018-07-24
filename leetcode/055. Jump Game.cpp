class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;
        vector<bool> result(nums.size(), false);
        if(nums.size() == 1) return true;
        
        if(nums[0]){
            result[0] = true;
            for(int i = 1; i <= nums[0]; i++) result[i] = true;
        }
        else{
            return false;
        }
        
        for(int i = 1; i < nums.size()-1; i++){
            if(result[i] != false) //can reach
                for(int j = i + 1; j <= nums[i] + i && j < nums.size(); j++) //nums[i] not zero
                    result[j] = true;
        }
        return result.back();
    }
};