class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() == 0) return 0;
        int result = 0;
        string prev = s.substr(0,1);
        string cur;
        int index = 1;
        for(; index < s.size() && prev[0] == s[index]; index++) prev = prev + s[index];
        if(index == s.size()) return 0;
        while(index < s.size()){
            for(cur = s.substr(index++, 1); index < s.size() && cur[0] == s[index]; index++) cur = cur + s[index];
            result += min(prev.size(), cur.size());
            prev = cur;
        }
        return result;
    }
};