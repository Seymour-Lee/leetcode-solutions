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