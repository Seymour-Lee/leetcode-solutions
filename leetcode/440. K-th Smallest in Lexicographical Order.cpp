class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        while(k){
            int steps = f(n, ans, ans+1);
            if(steps <= k) ans++, k-=steps;
            else ans *= 10, k--;
        }
        return ans;
    }
    
private:
    int f(long n, long n1, long n2){
        int ans = 0;
        while(n1 <= n){
            ans += min(n+1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return ans;
    }
};