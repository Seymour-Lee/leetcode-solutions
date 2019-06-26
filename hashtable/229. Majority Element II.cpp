class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        map<int, int> num2freq;
        for(auto num: nums) num2freq[num]++;
        for(auto e: num2freq) 
            if(e.second > nums.size()/3) result.push_back(e.first);
        return result;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> a2t;
        for(auto num: nums) a2t[num]++;
        for(auto p: a2t) if(p.second > nums.size()/3) ans.push_back(p.first);
        return ans;
    }
};