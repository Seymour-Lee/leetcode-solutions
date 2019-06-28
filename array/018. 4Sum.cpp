class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                int left = j + 1, right = n - 1;
                while(left < right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) for(int j = i+1; j < nums.size(); j++) {
            int x = j+1, y = nums.size()-1;
            while(x < y){
                if(nums[i]+nums[j]+nums[x]+nums[y] == target){
                    ans.insert({nums[i], nums[j], nums[x], nums[y]});
                    while(x+1 < nums.size() && nums[x] == nums[x+1]) x++;
                    while(y-1 > j && nums[y] == nums[y-1]) y--;
                    x++, y--;
                }
                else if(nums[i]+nums[j]+nums[x]+nums[y] < target) x++;
                else y--;
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};