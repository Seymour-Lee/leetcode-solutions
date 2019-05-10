class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() == 0) return true;
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            if(s[i] != s[j]){
                return isPalindrome(s.substr(i, j-i)) || isPalindrome(s.substr(i+1, j-i));
            }
        }
        return true;
    }
    
private:
    bool isPalindrome(string s){
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};

// TLE
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() == 0) return true;
        if(isPalindrome(s)) return true;
        for(int i = 0; i < s.size(); i++){
            if(isPalindrome(s.substr(0, i) + s.substr(i+1, s.size()-i-1))) return true;
        }
        return false;
    }
    
private:
    bool isPalindrome(string s){
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};