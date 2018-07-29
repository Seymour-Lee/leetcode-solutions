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