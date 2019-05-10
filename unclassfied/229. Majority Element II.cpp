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