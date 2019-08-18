class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        k2v[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(k2v.find(key) == k2v.end()) return "";
        int l = 0, r = k2v[key].size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(k2v[key][m].first <= timestamp) l = m + 1;
            else r = m;
        }
        l--;
        return l < 0? "": k2v[key][l].second;
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> k2v;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */