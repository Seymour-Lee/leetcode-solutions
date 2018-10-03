class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(key2val.find(key) == key2val.end()) return -1;
        int freq = key2freq[key];
        auto itor = find(freq2keys[freq].begin(), freq2keys[freq].end(), key);
        freq2keys[freq].erase(itor);
        if(freq2keys[freq].empty()) freq2keys.erase(freq2keys.find(freq));
        freq2keys[freq+1].push_front(key);
        key2freq[key]++;
        return key2val[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        if(key2val.find(key) != key2val.end()){
            key2val[key] = value;
            int freq = key2freq[key];
            auto itor = find(freq2keys[freq].begin(), freq2keys[freq].end(), key);
            freq2keys[freq].erase(itor);
            if(freq2keys[freq].empty()) freq2keys.erase(freq2keys.find(freq));
            key2freq[key] = freq+1;
            freq2keys[freq+1].push_front(key);
        }
        else{
            if(key2val.size() >= capacity){
                int leastFreqKey = freq2keys.begin()->second.back();
                    freq2keys.begin()->second.pop_back();
            if(freq2keys.begin()->second.empty()) freq2keys.erase(freq2keys.begin());
                key2val.erase(key2val.find(leastFreqKey));
                key2freq.erase(key2freq.find(leastFreqKey));
            }
            key2val[key] = value;
            key2freq[key] = 0;
            freq2keys[0].push_front(key);
        } 
    }
    
private:
    map<int, int> key2val;
    map<int, int> key2freq;
    map<int, list<int>> freq2keys;
    int capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */