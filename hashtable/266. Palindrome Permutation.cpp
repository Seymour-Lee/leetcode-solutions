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

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> ch2times;
        for(auto c: s) ch2times[c]++;
        int odds = 0;
        for(auto p: ch2times) if(p.second % 2 == 1) odds++;
        return odds <= 1;
    }
};