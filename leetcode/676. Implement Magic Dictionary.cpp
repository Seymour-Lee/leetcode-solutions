class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto e: dict) this->dict.insert(e);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto str: dict){
            if(word.size() != str.size()) continue;
            int counter = 1;
            for(int i = 0; i < str.size(); i++){
                if(str[i] != word[i]) counter--;
                if(counter < 0) break;
            }
            if(counter == 0) return true;
        }
        return false;
    }

private:
    set<string> dict;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */