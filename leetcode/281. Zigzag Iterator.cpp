class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int i = 0;
        while(i < v1.size() || i < v2.size()){
            if(i < v1.size()) q.push(v1[i]);
            if(i < v2.size()) q.push(v2[i]);
            i++;
        }
    }

    int next() {
        if(hasNext() == false)
            return -1;
        int ans = q.front();
        q.pop();
        return ans;
    }

    bool hasNext() {
        return q.size() > 0;
    }
    
private:
    queue<int> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */