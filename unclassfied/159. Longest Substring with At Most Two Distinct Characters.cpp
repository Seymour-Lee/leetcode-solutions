class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() <= 2) return s.size();
        unordered_map<char, int> ch2freq;
        int ans = 2;
        ch2freq[s[0]]++, ch2freq[s[1]]++;
        int i = 0, j = 2;
        while(i <= j && j < s.size()){
            ans = max(ans, j-i);
            if(ch2freq.size() == 2 && ch2freq.find(s[j]) == ch2freq.end()){
                while(i < j){
                    ch2freq[s[i]]--;
                    if(ch2freq[s[i]] == 0) break;
                    i++;
                }
                ch2freq.erase(s[i]);
                i++, ch2freq[s[j]]++;
            }
            else{
                ch2freq[s[j]]++;
            }
            j++;
        }
        return max(ans, j-i);
    }
};