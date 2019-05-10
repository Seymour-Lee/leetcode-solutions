class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        str2val[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for(auto it: str2val){
            if(it.first.substr(0, prefix.size()) == prefix){
                result += it.second;
            }
        }
        return result;
    }
    
private:
    map<string, int> str2val;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

class Trie {
public:
    Trie(){
        sum = 0;
    }
    
    void insert(string str, int val){
        Trie *node = this;
        for(auto c: str){
            if(node->children[c] == nullptr) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->sum = val;
    }
    
    int prefix(string str){
        Trie *node = this;
        for(auto c: str){
            if(node->children[c] == nullptr) return 0;
            node = node->children[c];
        }
        
        int ans = 0;
        queue<Trie *> q;
        q.push(node);
        while(q.empty() == false){
            auto p = q.front(); q.pop();
            if(p == nullptr) continue;
            ans += p->sum;
            for(auto c: p->children) q.push(c.second);
        }
        
        return ans;
    }
    
private:
    unordered_map<char, Trie *> children;
    int sum;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->prefix(prefix);
    }
    
private:
    Trie *trie;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */