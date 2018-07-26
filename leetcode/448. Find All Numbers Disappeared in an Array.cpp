class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) continue;
            if(nums[i] != i+1 && nums[i] == nums[nums[i]-1]){
                nums[i] = 0;
            }
            else if(nums[i] == i+1){
                continue;
            }
            else{
                swap(nums[i], nums[nums[i]-1]);
                i--;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) result.push_back(i+1);
        }
        return result;
    }
};