class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        unordered_map<int, int> m; 
        int ans = 1; 
        for (int i = 0; i < a.size(); i++) m[a[i]] = m[a[i]-d]+1;
        for (auto& it : m) if (it.second > ans) ans = it.second; 
        return ans; 
    }
};