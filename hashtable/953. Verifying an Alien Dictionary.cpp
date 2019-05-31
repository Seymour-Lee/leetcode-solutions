class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ch2pos;
        for(int i = 0; i < order.size(); i++) ch2pos[order[i]] = i;
        for(int i = 1; i < words.size(); i++){
            string str1 = words[i-1];
            string str2 = words[i];
            int pos = 0;
            for(pos = 0; pos < min(str1.size(), str2.size()); pos++){
                if(ch2pos[str1[pos]] < ch2pos[str2[pos]]) break;
                if(ch2pos[str1[pos]] > ch2pos[str2[pos]]) return false;
            }
            if(pos == min(str1.size(), str2.size()) && str1.size() > str2.size()) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ch2pos;
        for(int i = 0; i < order.size(); i++) ch2pos[order[i]] = i;
        for(int i = 1; i < words.size(); i++){
            string str1 = words[i-1];
            string str2 = words[i];
            int pos = 0;
            for(pos = 0; pos < min(str1.size(), str2.size()); pos++){
                if(ch2pos[str1[pos]] < ch2pos[str2[pos]]) break;
                if(ch2pos[str1[pos]] > ch2pos[str2[pos]]) return false;
            }
            if(pos == min(str1.size(), str2.size()) && str1.size() > str2.size()) return false;
        }
        return true;
    }
};