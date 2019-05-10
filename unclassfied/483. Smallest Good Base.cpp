class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = (unsigned long long)stoll(n);
        unsigned long long cur = 1;
        for(int i = 62; i >= 1; i--) if((cur << i) < num) {
            unsigned long long ans = f(num, i);
            if(ans != 0) return to_string(ans);
        }
        return to_string(num-1);
    }
    
private:
    unsigned long long f(unsigned long long n, int d){
        double num = double(n);
        unsigned long long r = (unsigned long long)(pow(num, 1.0/d)+1);
        unsigned long long l = 1;
        while(l <= r){
            unsigned long long m = l+ (r - l) / 2;
            unsigned long long sum = 1, cur = 1;
            for(int i = 1; i <= d; i++) cur *= m, sum += cur;
            if(sum == n) return m;
            if(sum > n) r = m-1;
            else l = m+1;
        }
        return 0;
    }
};