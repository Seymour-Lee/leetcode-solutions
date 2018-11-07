long countSubarrays(int numbers_count, int* numbers, int k) {
    if(k <= 1) return 0;
    long ans = 0;
    long prod = 1, left = 0;
    for(long right = 0; right < numbers_count; right++){
        // prod *= (long)*(numbers+right);
        // while(prod > (long)k) prod /= (long)*(numbers+left), left++;
        prod *= (long)numbers[right];
        while(prod > (long)k) prod /= numbers[left++];
        ans += (long)right - (long)left + 1;
    }
    return ans;
}

// https://lemire.me/blog/2013/12/26/fastest-way-to-compute-the-greatest-common-divisor/
unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

unsigned long long fastPow(int x, int n){
    if(n == 0) return 1;
    const unsigned int mod = 1000000000+7;
    if(n % 2 == 1){
        unsigned long long half = fastPow(x, n/2) % mod;
        //double half = binaryPow(x, n/2);
        return (((half * half) % mod) * x) % mod;
    }
    else{
        unsigned long long half = fastPow(x, n/2) % mod;
        // double half = binaryPow(x, n/2);
        return (half*half) % mod;
    }
}

int three(int rotorCount, int minRotorValue, int maxRotorValue){
    cout<<"Input is "<<rotorCount<<" "<<minRotorValue<<" "<<maxRotorValue<<endl;
    const int mod = 1000000000+7;
    unsigned long long ans = 0;
    unordered_map<int, int> num2primes;
    for(int i = minRotorValue; i <= maxRotorValue; i++){
        if(__gcd(i, i) == 1) num2primes[i]++;
        for(int j = i+1; j <= maxRotorValue; j++){
            if(__gcd(i, j) == 1){
                num2primes[i]++, num2primes[j]++;
            }
        }
    }
    for(auto p: num2primes){
        // cout<<p.first<<" "<<p.second<<endl;
        // cout<<pow(p.second, rotorCount-1)<<endl;
        // ans = (ans + fastPow(p.second, rotorCount-1)) % mod;
        // ans = (long)(ans + ((long)pow(p.second, rotorCount-1) % mod)) % mod;
        ans = (ans + fastPow(p.second, rotorCount-1) % mod) % mod;
    }
    return (int)ans;
}

int phi(int n) 
{ 
    int result = n; // Initialize result as n 
  
    // Consider all prime factors of n and subtract their 
    // multiples from result 
    for (int p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 

int main() {
    // int count = 3;
    // int nums[count] = {1, 2, 3};
    // int k = 4;
    // // ans should be 4
    
    // int count = 11;
    // int nums[count] = {4, 13, 20, 32, 44, 59, 61, 71, 75, 86, 88};
    // int k = 567601;
    // // ans should be 32
    // auto ans = countSubarrays(count, nums, k);
    // cout<<ans;
    auto ans = three(78, 4729, 5773); // 493396273
    // auto ans = three(3, 2, 6); // 34
    // auto ans = three(2, 1230, 1836); // 223466
    // auto ans = three(2, 1, 3); // 7
    // auto ans = three(3, 2, 4); // 6
    // cout<<ans;
    return 0;
}