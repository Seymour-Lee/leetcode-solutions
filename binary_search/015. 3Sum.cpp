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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<string> seen;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int t = 0 - nums[i] - nums[j];
                if(binary_search(nums.begin()+j+1, nums.end(), t)){
                    string str = to_string(nums[i])+","+to_string(nums[j])+","+to_string(t);
                    if(seen.find(str) == seen.end()){
                        ans.push_back({nums[i], nums[j], t});
                        seen.insert(str);
                    }
                } 
                while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2) return {};
        sort(nums.begin(), nums.end());
        for(auto num: nums) cout<<num<<" "; cout<<endl;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int j  = i+1, k = nums.size()-1;
            int target = 0 - nums[i];
            while(j < k){
                if(nums[j] + nums[k] == target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j < nums.size()-1 && nums[j] == nums[j+1]) j++;
                    while(k > 1 && nums[k] == nums[k-1]) k--;
                    j++, k--;
                }
                else if(nums[j] + nums[k] < target) j++;
                else k--;
            }
        }
        return ans;
    }
};