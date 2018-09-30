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