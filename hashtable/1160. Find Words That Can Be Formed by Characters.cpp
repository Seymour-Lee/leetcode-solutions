class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> c2t(26, 0);
        for(auto c: chars) c2t[c-'a']++;
        int ans = 0;
        for(auto str: words){
            vector<int> counter = vector<int>(26, 0);
            for(auto c: str) counter[c-'a']++;
            bool valid = true;
            for(int i = 0; i < 26; i++) if(counter[i] > c2t[i]){
                valid = false;
                break;
            }
            if(valid) ans += str.size();
        }
        return ans;
    }
};