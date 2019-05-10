class Solution {
public:
    int reverse(int x) {
        int result = 0;
        
        while(x != 0){
            int pop = x % 10;
            x = x / 10;
            if((result > INT_MAX / 10) || (result == INT_MAX / 10 && pop > 7)) return 0;
            if((result < INT_MIN / 10) || (result == INT_MIN / 10 && pop < -8)) return 0;   
            result = result * 10 + pop;
        }
        
        return result;
    }
};

class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        long num = x;
        string str = to_string(labs(num));
        long ans = stol(neg? "-"+string(str.rbegin(), str.rend()): string(str.rbegin(), str.rend()));
        return ans > INT_MAX || ans < INT_MIN? 0: ans;
    }
};

class Solution {
public:
    int reverse(int x) {
        bool sign = x > 0;
        string num = to_string(labs((long)x));
        std::reverse(num.begin(), num.end());
        long ans = sign? stol(num): -stol(num);
        return ans < INT_MIN || INT_MAX < ans? 0: ans;
    }
};

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        bool sign = x > 0;
        x = abs(x);
        int ans = 0;
        while(x){
            if(ans*10/5 != ans+ans) return 0;
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return sign? ans: -ans;
    }
};