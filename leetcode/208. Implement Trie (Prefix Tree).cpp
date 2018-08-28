class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        nodes = vector<Trie *>(children, nullptr);
        end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = this;
        for(auto ch: word){
            if(node->getChild(ch) == nullptr) node->setChild(ch);
            node = node->getChild(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = searchPrefix(word);
        return node != nullptr && node->isEnd() == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }
    
private:
    vector<Trie *> nodes;
    bool end;
    const int children = 26;
    
    bool isEnd(){
        return this->end;
    }
    
    void setEnd(){
        this->end = true;
    }
    
    Trie *getChild(char ch){
        return this->nodes[ch-'a'];
    }
    
    void setChild(char ch){
        this->nodes[ch-'a'] = new Trie();
    }
    
    Trie *searchPrefix(string word){
        auto node = this;
        for(auto ch: word){
            if(node->getChild(ch) == nullptr) return nullptr;
            else node = node->getChild(ch);
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */