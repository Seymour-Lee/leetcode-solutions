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

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev = 0, cur = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] != s[i]){
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            else{
                cur++;
            }
        }
        return ans + min(prev, cur);
    }
};