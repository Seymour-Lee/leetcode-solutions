class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> c2p;
        for(int i = 0;  i < keyboard.size(); i++) c2p[keyboard[i]] = i;
        int ans = 0;
        int i = 0;
        for(auto c: word){
            int j = c2p[c];
            ans += abs(i-j);
            i = j;
        }
        return ans;
    }
};