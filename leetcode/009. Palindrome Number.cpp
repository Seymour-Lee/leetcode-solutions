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