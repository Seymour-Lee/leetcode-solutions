class ExamRoom {
public:
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        int result = 0;
        if(used.size() > 0){
            int dis = *used.begin();
            int prev = -1;
            for(auto s: used){
                if(prev != -1){
                    int d = (s - prev) / 2;
                    if(d > dis){
                        dis = d;
                        result = prev + d;
                    }
                }
                prev = s;
            }
            if(n - 1 - *used.rbegin() > dis){
                result = n - 1;
            }
        }
        used.insert(result);
        return result;
    }
    
    void leave(int p) {
        used.erase(p);
    }
    
private:
    set<int> used;
    int n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */