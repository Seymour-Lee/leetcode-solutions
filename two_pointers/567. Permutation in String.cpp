// TLE
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        if(s1.size() == 0) return true;
        if(s2.find(s1) != string::npos) return true;
        string prev = s1;
        while(prev_permutation(prev.begin(), prev.end())){
            if(s2.find(prev) != string::npos) return true;
        }
        string next = s1;
        while(next_permutation(next.begin(), next.end())){
            if(s2.find(next) != string::npos) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        if(s1.size() == 0) return true;
        vector<int> win(26, 0);
        vector<int> zeros(26, 0);
        for(auto ch: s1) win[ch-'a']++;
        for(int i = 0; i < s1.size(); i++) win[s2[i]-'a']--;
        if(win == zeros) return true;
        for(int i = 1, j = s1.size(); j < s2.size(); i++, j++){
            win[s2[i-1]-'a']++;
            win[s2[j]-'a']--;
            if(win == zeros) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> counter(26, 0);
        for(auto c: s1) counter[c-'a']++;
        vector<int> cur(26, 0);
        for(int i = 0; i < s2.size(); i++){
            cur[s2[i]-'a']++;
            if(i >= s1.size()) cur[s2[i-s1.size()]-'a']--;
            if(cur == counter) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> cnt(26, 0), cur(26, 0);
        for(auto &c: s1) cnt[c-'a']++;
        for(int i = 0; i < s2.size(); i++){
            cur[s2[i]-'a']++;
            if(i >= s1.size()) cur[s2[i-s1.size()]-'a']--;
            if(cur == cnt) return true;
        }
        return false;
    }
};