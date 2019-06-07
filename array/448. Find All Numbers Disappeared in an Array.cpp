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

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) if(nums[i] != 0 && nums[i] != i+1){
            if(nums[i] == nums[nums[i]-1]) nums[i] = 0;
            else swap(nums[i], nums[nums[i]-1]), i--;
        }
        for(int i = 0; i < nums.size(); i++) if(nums[i] == 0) ans.push_back(i+1);
        return ans;
    }
};