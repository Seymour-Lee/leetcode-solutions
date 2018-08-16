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