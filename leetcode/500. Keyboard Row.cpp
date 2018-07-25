class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for(auto word: words){
            if(inOneRow(word)) result.push_back(word);
        }
        return result;
    }
    
private:
    set<char> set1 = {'q','w','e','r','t','y','u','i','o','p'};
    set<char> set2 = {'a','s','d','f','g','h','j','k','l'};
    set<char> set3 = {'z','x','c','v','b','n','m'};
    bool inOneRow(string str){
        if(str == "") return true;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        set<char> &s = set1.find(str[0])!=set1.end()? set1: set2.find(str[0])!=set2.end()? set2: set3;
        for(auto c: str){
            if(s.find(c) == s.end()) return false;
        }
        return true;
    }
};