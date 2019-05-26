class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(k2v.find(key) == k2v.end()) return -1;
        pos.remove(key);
        pos.push_front(key);
        k2v[key] = {k2v[key].first, pos.begin()};
        return k2v[key].first;
    }
    
    void put(int key, int value) {
        if(k2v.size() == cap && k2v.find(key) == k2v.end()){
            k2v.erase(pos.back());
            pos.pop_back();
        }
        else if(k2v.find(key) != k2v.end()){
            pos.remove(key);
        }
        k2v[key] = {value, pos.begin()};
        pos.push_front(key);
    }
    
private:
    map<int, pair<int, list<int>::iterator>> k2v;
    list<int> pos;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(k2v.find(key) == k2v.end()) return -1;
        keypos.remove(key);
        keypos.push_front(key);
        k2v[key] = {k2v[key].first, keypos.begin()};
        return k2v[key].first;
    }
    
    void put(int key, int value) {
        if(k2v.size() == capacity && k2v.find(key) == k2v.end()){
            k2v.erase(keypos.back());
            keypos.pop_back();
        }
        else if(k2v.find(key) != k2v.end()){
            keypos.remove(key);
        }
        keypos.push_front(key);
        k2v[key] = {value, keypos.begin()};
    }
    
private:
    unordered_map<int, pair<int, list<int>::iterator>> k2v;
    list<int> keypos;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(k2v.find(key) == k2v.end()) return -1;
        keypos.remove(key);
        keypos.push_front(key);
        return k2v[key];
    }
    
    void put(int key, int value) {
        if(k2v.size() == capacity && k2v.find(key) == k2v.end()){
            k2v.erase(keypos.back());
            keypos.pop_back();
        }
        else if(k2v.find(key) != k2v.end()){
            keypos.remove(key);
        }
        keypos.push_front(key);
        k2v[key] = value;
    }
    
private:
    unordered_map<int, int> k2v;
    list<int> keypos;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

class LRUCache {
public:
    LRUCache(int capacity) {
        num = 0;
        cap = capacity;
    }
    
    int get(int key) {
        if(key2itor.find(key) == key2itor.end()) return -1;
        cache.erase(key2itor[key]);
        cache.push_front(key);
        key2itor[key] = cache.begin();
        return key2val[key];
    }
    
    void put(int key, int value) {
        if(key2val.find(key) != key2val.end()){
            cache.erase(key2itor[key]);
        }
        else if(key2val.size() == cap){
            key2itor.erase(cache.back());
            key2val.erase(cache.back());
            cache.pop_back();
        }
        key2val[key] = value;
        cache.push_front(key);
        key2itor[key] = cache.begin();
    }
    
private:
    int num;
    int cap;
    list<int> cache;
    unordered_map<int, list<int>::iterator> key2itor;
    unordered_map<int, int> key2val;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */