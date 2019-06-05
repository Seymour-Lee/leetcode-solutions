class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() == 0) return true;
        if(ransomNote.size() > magazine.size()) return false;
        map<char, int> table;
        for(auto c: magazine) table[c]++;
        for(auto c: ransomNote){
            if(table.find(c) == table.end()) return false;
            if(--table[c] < 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> p(26, 0);
        for(auto c: magazine) p[c-'a']++;
        for(auto c: ransomNote) if(--p[c-'a'] < 0) return false;
        return true;
    }
};