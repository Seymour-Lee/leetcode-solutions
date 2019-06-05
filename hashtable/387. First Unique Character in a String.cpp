class Solution {
public:
    int firstUniqChar(string s) {
        if(s == "") return -1;
        int result = INT_MAX;
        map<char, int> table;
        for(auto c: s) table[c]++;
        set<char> unique;
        for(auto item: table){
            if(item.second == 1){
                unique.insert(item.first);
            }
        }
        if(unique.empty()) return -1;
        for(int i = 0; i < s.size(); i++){
            if(unique.find(s[i]) != unique.end()){
                result = i;
                break;
            }
        }
        return result;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> c(26, 0), p(26, s.size());
        for(int i = 0; i < s.size(); i++) c[s[i]-'a']++, p[s[i]-'a'] = min(p[s[i]-'a'], i);
        int ans = s.size();
        for(int i = 0; i < c.size(); i++) if(c[i] == 1) ans = min(ans, p[i]);
        return ans == s.size()? -1: ans;
    }
};