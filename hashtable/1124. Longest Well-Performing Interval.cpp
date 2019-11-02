class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> arr;
        for(auto h: hours) if(h > 8) arr.push_back(1); else arr.push_back(0);
        unordered_map<int, int> um; 
        int sum = 0, maxLen = 0; 
        for (int i = 0; i < n; i++) { 
            sum += arr[i] == 0 ? -1 : 1; 
            if (sum >= 1) maxLen = i + 1; 
            else if (um.find(sum) == um.end()) um[sum] = i; 
            if (um.find(sum - 1) != um.end()) { 
                if (maxLen < (i - um[sum - 1])) 
                    maxLen = i - um[sum - 1]; 
            } 
        } 
        return maxLen; 
    }
};