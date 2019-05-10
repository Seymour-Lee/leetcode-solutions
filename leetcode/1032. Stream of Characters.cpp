class Trie{
public:
    Trie(){
        children = vector<Trie *>(26, nullptr);
        end = false;
    }
    
    void insert(string &str){
        Trie * node = this;
        reverse(str.begin(), str.end());
        for(auto c: str){
            int pos = c - 'a';
            if(node->children[pos] == nullptr) node->children[pos] = new Trie();
            node = node->children[pos];
        }
        node->end = true;
    }
    
    bool search(string &str){
        Trie * node = this;
        for(auto itor = str.rbegin(); itor != str.rend(); itor++){
            int pos = *itor - 'a';
            if(node->children[pos] == nullptr) return false;
            node = node->children[pos];
            if(node->end) return true;
        }
        return false;
    }
    
private:
    vector<Trie *> children;
    bool end;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for(auto w: words) trie.insert(w);
    }
    
    bool query(char letter) {
        str.push_back(letter);
        return trie.search(str);
    }

private:
    Trie trie;
    string str;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

\class Trie{
public:
    Trie(): children(vector<Trie*>(26, nullptr)), end(false){}
    
    void insert(string &str){
        reverse(str.begin(), str.end());
        auto node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->end = true;
    }
    
    bool search(string &str){
        auto node = this;
        for(auto c: str){
            int i = c - 'a';
            if(node->children[i] == nullptr) return false;
            node = node->children[i];
            if(node->end) return true;
        }
        return node->end;
    }
    
private:
    vector<Trie *> children;
    bool end;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for(auto &w: words) trie->insert(w), maxlen = max(maxlen, (int)w.size());
    }
    
    bool query(char letter) {
        str = letter + str;
        if(str.size() > maxlen) str.pop_back();
        return trie->search(str);
    }

private:
    string str;
    int maxlen = 0;
    Trie *trie = new Trie();
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */