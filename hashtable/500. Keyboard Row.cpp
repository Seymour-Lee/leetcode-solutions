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

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> char2val = {
            {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1}, 
            {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2}, 
            {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}};
        vector<string> ans;
        for(auto &str: words){
            if(str == ""){
                ans.push_back(str);
                continue;
            }
            string ori = str;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            int val = char2val[str[0]];
            bool right = true;
            for(auto c: str) if(char2val[c] != val){
                right = false;
                break;
            }
            if(right) ans.push_back(ori);
        }
        return ans;
    }
};