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

class Solution {
public:
    int primePalindrome(int N) {
        if(N <= 2) return 2;
        if(N > 7 && N <= 11) return 11;
        for(int i = 1; i < 999999; i++){
            auto palin = reverse(i);
            if(palin >= N && isPrime(palin)) return palin;
        }
        return -1;
    }
    
    int reverse(int x){
        auto s = to_string(x), t = s;
        std::reverse(t.begin(), t.end());
        s.pop_back();
        return stoi(s+t);
    }
    
    bool isPrime(int x){
        if(x%2 == 0) return false;
        int sq = int(sqrt(x)) + 1;
        for(int i = 3; i<=sq; i+= 2)
            if(x % i == 0) return false;
        return true;
    }
};