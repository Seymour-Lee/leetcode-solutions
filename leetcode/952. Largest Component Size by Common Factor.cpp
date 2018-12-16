// TLE
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        vector<int> p(A.size(), -1);
        vector<int> s(A.size(), 1);
        for(int i = 0; i < A.size(); i++){
            for(int j = i+1; j < A.size(); j++){
                if(gcd(A[i], A[j]) > 1){
                    u(p, s, i, j);
                }
            }
        }
        return *max_element(s.begin(), s.end());
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return f(p, p[x]);
    }
    
    void u(vector<int> &p, vector<int> &s, int x, int y){
        int xp = f(p, x);
        int yp = f(p, y);
        if(xp != yp) p[xp] = yp, s[yp] += s[xp];
    }
    
    unsigned int gcd(unsigned int u, unsigned int v){
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
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        vector<int> prime = primes(*max_element(A.begin(), A.end()));
        for(auto a: A) p[a] = a;
        for(auto e: prime) p[e] = e;
        for(auto a: A){
            int cur = a;
            for(auto base: prime){
                if(cur % base == 0){
                    if(f(base) != f(a)) u(base, a);
                    while(cur % base == 0) cur = cur / base;
                }
                if(base > cur) break;
            }
            if(cur > 1){
                if(p.find(cur) == p.end()) p[cur] = cur;
                u(cur, a);
            }
        }
        unordered_map<int, int> stat;
        for(auto a: A) stat[f(a)]++;
        int ans = 0;
        for(auto e: stat) ans = max(ans, e.second);
        return ans;
    }
    
private:
    unordered_map<int, int> p;
    int f(int x){
        if(p[x] != x) p[x] = f(p[x]);
        return p[x];
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
    
    vector<int> primes(int n){
        vector<bool> prime(n, true);
        vector<int> ans;
        for(long i = 2; i < n; i++){
            if(prime[i]){
                ans.push_back(i);
                for(long j = i*i; j < n; j+=i){
                    prime[j] = false;
                }
            }
        }
        return ans;
    }
};