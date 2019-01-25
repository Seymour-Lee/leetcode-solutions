class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        int result = 0;
        int cur = x;
        while(cur){
            result = result * 10 + cur % 10;
            cur = cur / 10;
        }
        
        return x == result;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        string b(a.rbegin(), a.rend());
        return a == b;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x <= 0) return x == 0;
        string num = to_string(x);
        return num == string(num.rbegin(), num.rend());
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x <= 0) return x == 0;
        int ans = 0;
        int cur = x;
        while(cur){
            if(ans*10/5 != ans+ans) return false;
            ans = ans * 10 + cur % 10;
            cur = cur / 10;
        }
        return ans == x;
    }
};