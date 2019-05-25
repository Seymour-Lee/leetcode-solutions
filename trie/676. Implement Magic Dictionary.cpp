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

class Trie{
public:
    Trie(){
        children = vector<Trie *>(nodes, nullptr);
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
        Trie *node = this;
        for(auto c: str){
            int i = c-'a';
            if(node->children[i] == nullptr) return false;
            node = node->children[i];
        }
        return node != nullptr && node->end;
    }
    
private:
    vector<Trie *> children;
    bool end;
    const int nodes = 26;
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto str: dict) trie->insert(str);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto &c: word){
            char ori = c;
            for(c = 'a'; c <= 'z'; c++){
                if(c == ori) continue;
                if(trie->search(word)) return true;
            }
            c = ori;
        }
        return false;
    }
    
private:
    Trie *trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

class Trie{
public:
    Trie(): cs(vector<Trie *>(26, nullptr)), end(false){}
    
    void insert(string str){
        auto node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->cs[i] == nullptr) node->cs[i] = new Trie();
            node = node->cs[i];
        }
        node->end = true;
    }
    
    bool search(string &word) {
        auto node = this;
        bool changed = false;
        for(auto c: word){
            if(node->cs[c-'a'] == nullptr) return false;
            node = node->cs[c-'a'];
        }
        return node->end;
    }
    
    
    
private:
    vector<Trie *> cs;
    bool end;
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &str: dict) trie->insert(str);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto &c: word){
            char ori = c;
            for(c = 'a'; c <= 'z'; c++){
                if(c == ori) continue;
                if(trie->search(word)) return true;
            }
            c = ori;
        }
        return false;
    }
    
private:
    Trie *trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */