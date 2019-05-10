class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        if(words.size() == 0 || pattern == "") return result;
        map<char, char> p2w;
        set<char> repeat;
        for(auto word: words){
            p2w.clear();
            bool right = true;
            if(word.size() != pattern.size()) continue;
            for(int i = 0; i < word.size(); i++){
                if(p2w.find(pattern[i]) == p2w.end()) p2w[pattern[i]] = word[i];
                else if(p2w[pattern[i]] != word[i]){
                    right = false;
                    break;
                }
            }
            repeat.clear();
            for(auto e: p2w){
                if(repeat.find(e.second) != repeat.end()){
                    right = false;
                    break;
                }
                repeat.insert(e.second);
            }
            if(right) result.push_back(word);
        }
        return result;
    }
};