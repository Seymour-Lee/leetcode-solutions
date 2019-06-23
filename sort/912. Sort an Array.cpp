class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int> nums) {
        if(nums.size() <= 1) return nums;
        vector<int> ans;
        int m = nums.size()/2;
        vector<int> l = sortArray(vector<int>(nums.begin(), nums.begin()+m));
        vector<int> r = sortArray(vector<int>(nums.begin()+m, nums.end()));
        int i = 0, j = 0;
        while(i < l.size() || j < r.size()){
            int a = i < l.size()? l[i]: INT_MAX;
            int b = j < r.size()? r[j]: INT_MAX;
            if(a < b) ans.push_back(a), i++;
            else ans.push_back(b), j++;
        }
        return ans;
    }
};