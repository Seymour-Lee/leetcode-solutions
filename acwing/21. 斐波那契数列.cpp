class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        n -= 2;
        int ans = 1;
        int a = 1, b = 1;
        while(n-- > 0) a = b, b = ans, ans = a+b;
        return ans;
    }
};