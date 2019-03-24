class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0) return -1;
        if(K % 5 == 0) return -1;
        
        if(K == 1) return 1;
        int r = 1, p = 1;
        for(int i = 2; ; i++){
            p = ((p%K)*(10%K))%K;
            r = (r%K + p%K) % K;
            if(r == 0) return i;
        }
        return -1;
    }
};