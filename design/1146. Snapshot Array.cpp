class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr = vector<vector<pair<int, int>>>(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        if(arr[index].size() && arr[index].back().first == counter){
            arr[index].pop_back();
        }
        arr[index].push_back({counter, val});
        
    }
    
    int snap() {
        return counter++;
    }
    
    int get(int i, int snap_id) {
        int l = 0, r = arr[i].size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(arr[i][m].first <= snap_id) l = m + 1;
            else r = m;
        }
        return arr[i][l-1].second;
    }
    
private:
    int counter = 0;
    
    vector<vector<pair<int, int>>> arr;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */