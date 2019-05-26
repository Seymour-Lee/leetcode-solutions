class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.insert(t);
        auto end = pings.lower_bound(t);
        auto begin = pings.upper_bound(t-3000-1);
        return distance(begin, end)+1;
    }
    
private:
    set<int> pings;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(q.empty() == false && t-q.front()>3000) q.pop();
        q.push(t);
        return q.size();
    }
    
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */