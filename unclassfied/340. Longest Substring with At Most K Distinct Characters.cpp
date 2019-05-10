class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> ch2cnt;
        int ans = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            ch2cnt[s[j]]++;
            while(ch2cnt.size() > k){
                if(--ch2cnt[s[i]] == 0) ch2cnt.erase(s[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};