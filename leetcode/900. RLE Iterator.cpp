class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        reverse(A.begin(), A.end());
        vec = A;
    }
    
    int next(int n) {
        while(vec.empty() == false && n > vec.back()){
            n -= vec.back();
            vec.pop_back();
            vec.pop_back();
        }
        if(vec.empty()) return -1;
        vec.back() -= n;
        int ans = vec[vec.size()-2];
        if(vec.back() == 0){
            vec.pop_back();
            vec.pop_back();
        }
        return ans;
    }
    
private:
    vector<int> vec;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */