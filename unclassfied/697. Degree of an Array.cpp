class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int result = INT_MAX;
        map<int, int> times;
        map<int, int> firsts;
        map<int, int> lasts;
        for(int i = 0; i < nums.size(); i++){
            times[nums[i]]++;
            if(firsts.find(nums[i]) == firsts.end()) firsts[nums[i]] = i;
            lasts[nums[i]] = i;
        }
        int most = 0;
        for(auto time: times) most = max(most, time.second);
        set<int> degrees;
        for(auto time: times){
            if(time.second == most){
                degrees.insert(time.first);
            }
        }
        for(auto degree: degrees){
            result = min(result, lasts[degree]-firsts[degree]+1);
        }
        return result;
    }
};