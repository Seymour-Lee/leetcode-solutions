class Solution {
public:
    int primePalindrome(int N) {
        if(N == 1) return 2;
        if(N == 2) return 2;
        N = N % 2 == 0? N+1: N;
        for(; !(N == reverse(N) && isPrime(N)); N+=2){
            if(10000000 < N && N < 100000000) N = 100000001;
        }
        return N;
    }
    
private:
    bool isPrime(int N){
        int sq = sqrt(N);
        for(int i = 2; i <= sq; i++)
            if(N % i == 0) return false;
        return true;
    }
    
    int reverse(int N){
        int res = 0;
        while(N){
            res = 10 * res + (N % 10);
            N = N / 10;
        }
        return res;
    }
    
};