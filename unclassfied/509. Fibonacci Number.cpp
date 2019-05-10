class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        int pprev = 0;
        int prev = 1;
        int i = 1;
        while(i < N){
            int ppprev = pprev;
            pprev = prev;
            prev = prev + ppprev;
            i++;
        }
        return prev;
    }
};