class RangeModule {
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        removeRange(left, right);
        m[left] = right;
        auto it = m.find(left);
        if (it != m.begin() && prev(it)->second == left) {
            (--it)->second = right;
            m.erase(left);
        }
        if (it != prev(m.end()) && next(it)->first == right) {
            it->second = next(it)->second;
            m.erase(next(it));
        }
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (m.empty() || it == m.begin()) return false;
        return (--it)->second >= right;
    }
    
    void removeRange(int left, int right) {
        if (m.empty()) return;
        auto it = m.lower_bound(left);
        if (it != m.begin()) it--;
        vector<int> v;
        while (it != m.end() && it->first < right) {
            if (it->first < left && it->second > left) {
                int tmp = it->second;
                it->second = left;
                if (tmp > right) {
                    m[right] = tmp;
                }
            } 
            else if (it->first >= left) {
                v.push_back(it->first);
                if (it->second > right) {
                    m[right] = it->second;
                }
            }
            it++;
        }
        for (int i : v) m.erase(i);
    }
    
private:
    map<int, int> m;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */