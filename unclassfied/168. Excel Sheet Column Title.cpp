class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        
        while(n){
            char cur = n % 26 == 0? 'Z': (n % 26) + 'A' - 1;
            result = cur + result;
            n = n % 26 == 0? n / 26 - 1: n / 26;
        }
        
        return result;
    }
};