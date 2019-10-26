class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        set<int> appeared;
        for(auto num: nums){
            if(appeared.find(num) == appeared.end()){
                appeared.insert(num);
            }
            else{
                result.push_back(num);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i])-1] >= 0){
                nums[abs(nums[i])-1] *= -1;
            }
            else{
                ans.push_back(abs(nums[i]));
            }
        }
        return ans;
    }
};