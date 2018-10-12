class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(auto s:dictionary) {     
            if(!dict.count(s)) bw.insert(s[0] + to_string(s.size()-2)+s[s.size()-1]);
            dict.insert(s);
        }    
    }
    
    bool isUnique(string word) {
        string abbr = word[0] + to_string(word.size()-2) + word[word.size()-1];
        return (bw.count(abbr) < 1) || ((dict.count(word) == 1) && (bw.count(abbr) == 1));       
    }
    
private:
    unordered_set<string> dict;
    unordered_multiset<string> bw;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */