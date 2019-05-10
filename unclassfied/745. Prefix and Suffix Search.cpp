class Trie{
public:
    Trie(){
        children = vector<Trie *>(27, nullptr);
        weight = -1;
    }
    
    void insert(string str, int w){
        Trie *node = this;
        for(auto c: str){
            int i = (c == '#'? 26: c-'a');
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
            node->weight = w;
        }
    }
    
    int search(string str){
        Trie *node = this;
        for(auto c: str){
            int i = (c == '#'? 26: c-'a');
            if(node->children[i] == nullptr) return -1;
            node = node->children[i];
        }
        return node->weight;
    }
    
private:
    vector<Trie *> children;
    int weight;
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        for(int i = 0; i < words.size(); i++){
            string str = words[i];
            // string rev = string(str.rbegin(), str.rend());
            for(int len = 0; len <= str.size(); len++){
                trie.insert(str.substr(len)+"#"+str, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.search(suffix + "#" + prefix);
    }
    
private:
    Trie trie;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */