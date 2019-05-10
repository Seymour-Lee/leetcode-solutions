class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> ch2freq;
        for(auto ch: s) ch2freq[ch]++;
        set<int> uni;
        for(auto it: ch2freq) if(it.second % 2 == 1) uni.insert(it.first);
        return uni.size() == 1 || uni.size() == 0;
    }
};