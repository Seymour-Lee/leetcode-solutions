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

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> n2t;
        unordered_map<int, int> l, r;
        for(int i = 0; i < nums.size(); i++){
            n2t[nums[i]]++;
            if(l.find(nums[i]) == l.end()) l[nums[i]] = i;
            r[nums[i]] = i;
        }
        int maxval = nums.front();
        for(auto p: n2t) if(p.second > n2t[maxval]) maxval = p.first;
        int ans = nums.size();
        for(auto p: n2t) if(p.second == n2t[maxval]){
            int val = p.first;
            ans = min(ans, r[val]-l[val]+1);
        }
        
        return ans;
    }
};