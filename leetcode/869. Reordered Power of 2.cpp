class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(isPowerOf2(N)) return true;
        string next = to_string(N);
        while(next_permutation(next.begin(), next.end())){
            if(next[0] != '0' && isPowerOf2(stoi(next))) return true;
        }
        string pre = to_string(N);
        while(prev_permutation(pre.begin(), pre.end())){
            if(pre[0] != '0' && isPowerOf2(stoi(pre))) return true;
        }
        return false;
    }
    
private:
    bool isPowerOf2(int n){
        while(n > 0 && (n & 0x1) == 0) n = n >> 1;
        return n == 1;
    }
};