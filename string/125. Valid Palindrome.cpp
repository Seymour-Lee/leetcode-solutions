class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "") return true;
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            while(!isalnum(s[i])) i++;
            while(!isalnum(s[j])) j--;
            if(i >= j) break;
            if(tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string str) {
        if(str.size() == 0) return true;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        int i = 0, j = str.size()-1;
        while(i < j){
            while(i < str.size() && !isalnum(str[i])) i++;
            while(j >= 0 && !isalnum(str[j])) j--;
            if(i >= j) break;
            if(str[i] != str[j]) return false;
            i++, j--;
        }
        return true;
    }
};