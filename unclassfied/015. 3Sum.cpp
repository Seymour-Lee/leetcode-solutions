// TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<multiset<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0)
                        s.insert(multiset<int>{nums[i], nums[j], nums[k]});
                    if(nums[i] + nums[j] + nums[k] > 0) break;
                }
            }
        }
        for(auto sub: s){
            vector<int> cur = {};
            for(auto e: sub) cur.push_back(e);
            result.push_back(cur);
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int ele = nums[i];
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int l = i+1, r = nums.size()-1, sum = 0-ele;
                if(sum < 0) break;
                while(l < r){
                    if(nums[l] + nums[r] == sum){
                        result.push_back(vector<int>
                                         {nums[i], nums[l], nums[r]});
                        while(nums[l] == nums[l+1]) l++;
                        while(nums[r] == nums[r-1]) r--;
                        l++, r--;
                    }
                    else if(nums[l] + nums[r] > sum) r--;
                    else l++;
                }
            }
        }
        return result;
    }
};