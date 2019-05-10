// TLE
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        dict.clear();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        dict.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.find('.') == string::npos) return dict.find(word) != dict.end();
        for(auto str: dict){
            if(str.size() == word.size() && backtracking(str, word, 0)) 
                return true;
        }
        return false;
    }
    
private:
    set<string> dict;
    
    bool backtracking(string target, string word, int pos){
        if(pos == word.size()) return true;
        if(word[pos] == '.' || word[pos] == target[pos]) 
            return backtracking(target, word, pos+1);
        else
            return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

class Trie{
public:
    Trie(){
        weight = -1;
        nodes = vector<Trie *>(26, nullptr);
    }
    
    void insert(string s, int weight = 0){
        auto node = this;
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(node->nodes[c] == nullptr){
                node->nodes[c] = new Trie();
            }
            node = node->nodes[c];
        }
        node->weight = weight;
    }
    
    bool search(string s){
        auto prev = this;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.'){
                string sub = s.substr(i+1);
                for(int j = 0; j < 26; j++){
                    if(prev->nodes[j]){
                        if(prev->nodes[j]->search(sub))
                            return true;
                    }
                }
                return false;
            }
            else{
                char c = s[i] - 'a';
                prev = prev->nodes[c];
                if(prev == nullptr) return false;
            }
        }
        return prev->weight >= 0;
    }
    
private:
    vector<Trie *> nodes;
    int weight;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->search(word);
    }
    
private:
    Trie *trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


class Trie {
public:
    Trie(){
        children = vector<Trie *>(26, nullptr);
        end = false;
    }
    
    void insert(string str){
        Trie *node = this;
        for(auto c: str){
            int i = c-'a';
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->end = true;
    }
    
    bool search(string str){
        queue<Trie *> q;
        q.push(this);
        for(auto c: str){
            int size = q.size();
            while(size--){
                auto node = q.front(); q.pop();
                if(c == '.'){
                    for(auto kid: node->children) if(kid) q.push(kid);
                }
                else{
                    if(node->children[c-'a']) q.push(node->children[c-'a']);
                }
            }
        }
        while(q.empty() == false){
            if(q.front()->end) return true;
            q.pop();
        }
        return false;
    }
private:
    vector<Trie *> children;
    bool end;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie->search(word);
    }
    
private:
    Trie *trie;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */