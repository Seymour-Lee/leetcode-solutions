class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> s;
        int result = 0;
        int size = nums.size();
        
        for(int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (abs(nums[i] - nums[j]) == k && s.find(nums[i] + nums[j]) == s.end()) {
                    result++;
                    s.insert(nums[i] + nums[j]);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            if(binary_search(nums.begin() + i+1, nums.end(), k+nums[i])){
                ret++;
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]){
                i++;
            }
        }       
        return ret;
    }
};