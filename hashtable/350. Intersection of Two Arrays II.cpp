class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int, int> numToTimes;
        for(auto num: nums1) numToTimes[num]++;
        for(auto num: nums2){
            if(numToTimes.find(num) != numToTimes.end() && numToTimes[num] != 0){
                result.push_back(num);
                numToTimes[num]--;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n2t;
        for(auto n: nums1) n2t[n]++;
        vector<int> ans;
        for(auto n: nums2) if(n2t.find(n) != n2t.end()){
            n2t[n]--;
            ans.push_back(n);
            if(n2t[n] == 0) n2t.erase(n);
        }
        return ans;
    }
};