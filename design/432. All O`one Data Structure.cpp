class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(key2itor.find(key) == key2itor.end()){
            if(val2keys.empty() || val2keys.back().val != 1)
                val2keys.push_back(data(1));
            auto itor = prev(val2keys.end());
            itor->keys.insert(key);
            key2itor[key] = itor;
        }
        else{
            auto itor = key2itor[key];
            itor->keys.erase(key);
            int val = itor->val + 1;
            if(itor == val2keys.begin()){
                val2keys.push_front(data(val));
            }
            itor--;
            itor->keys.insert(key);
            key2itor[key] = itor;
            itor++;
            if(itor->keys.empty()) val2keys.erase(itor);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(key2itor.find(key) == key2itor.end()) return;
        auto itor = key2itor[key];
        int val = itor->val - 1;
        itor->keys.erase(key);
        if(val == 0){
            key2itor.erase(key);
        }
        else{
            itor++;
            if(itor == val2keys.end() || itor->val != val) val2keys.insert(itor, data(val)), itor--;
            itor->keys.insert(key);
            key2itor[key] = itor;
            itor--;
        }
        if(itor->keys.empty()) val2keys.erase(itor);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(val2keys.empty()) return "";
        data ans = val2keys.front();
        return *ans.keys.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(val2keys.empty()) return "";
        data ans = val2keys.back();
        return *ans.keys.begin();
    }
    
private:
    struct data{
        int val;
        unordered_set<string> keys;
        data(int v): val(v) {}
    };
    list<data> val2keys; // large to small
    unordered_map<string, list<data>::iterator> key2itor;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(key2itor.find(key) == key2itor.end()){
            if(val2keys.empty() || val2keys.back().val != 1)
                val2keys.push_back(data(1));
            auto itor = prev(val2keys.end());
            itor->keys.insert(key);
            key2itor[key] = itor;
        }
        else{
            auto itor = key2itor[key];
            itor->keys.erase(key);
            int val = itor->val + 1;
            if(itor == val2keys.begin()){
                val2keys.push_front(data(val));
            }
            itor--;
            itor->keys.insert(key);
            key2itor[key] = itor;
            itor++;
            if(itor->keys.empty()) val2keys.erase(itor);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(key2itor.find(key) == key2itor.end()) return;
        auto itor = key2itor[key];
        int val = itor->val - 1;
        itor->keys.erase(key);
        if(val == 0){
            key2itor.erase(key);
        }
        else{
            itor++;
            if(itor == val2keys.end() || itor->val != val) val2keys.insert(itor, data(val)), itor--;
            itor->keys.insert(key);
            key2itor[key] = itor;
            itor--;
        }
        if(itor->keys.empty()) val2keys.erase(itor);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(val2keys.empty()) return "";
        data ans = val2keys.front();
        return *ans.keys.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(val2keys.empty()) return "";
        data ans = val2keys.back();
        return *ans.keys.begin();
    }
    
private:
    struct data{
        int val;
        unordered_set<string> keys;
        data(int v): val(v) {}
    };
    list<data> val2keys; // large to small
    unordered_map<string, list<data>::iterator> key2itor;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */