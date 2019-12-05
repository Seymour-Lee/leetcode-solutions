class Solution {
public:
    int numPrimeArrangements(int n) {
        long long ans = 1;
        int counter = 1;
        int mod = 1e9+7;
        auto f = [](int n){
            for(int i = 2; i*i <= n; i++) if(n % i == 0) return false;
            return true;
        };
        for(int i = 3; i <= n; i++) if(f(i)) counter++;
        for(int i = 1; i <= counter; i++) ans = (ans*i) % mod;
        for(int i = 1; i <= n-counter; i++) ans = (ans*i) % mod;
        return ans;
    }
};

class Solution {
public:
    int numPrimeArrangements(int n) {
        long long ans = 1;
        int counter = 1;
        int mod = 1e9+7;
        auto f = [](int n){
            for(int i = 2; i*i <= n; i++) if(n % i == 0) return false;
            return true;
        };
        for(int i = 3; i <= n; i++) if(f(i)) counter++;
        for(int i = 1; i <= counter; i++) ans = (ans*i) % mod;
        for(int i = 1; i <= n-counter; i++) ans = (ans*i) % mod;
        return ans;
    }
};