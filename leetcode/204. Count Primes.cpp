class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        for(int i = 2; i*i <= n; i++){
            if(isPrime[i]){
                for(int j = i*2; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        int counter = 0;
        for(int i = 2; i < n; i++){
            if(isPrime[i]) counter++;
        }
        return counter;
    }
};