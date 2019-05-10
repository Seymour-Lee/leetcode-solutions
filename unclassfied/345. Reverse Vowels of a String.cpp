class Solution {
public:
    string reverseVowels(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--){
            while(!isVowel(s[i])) i++;
            while(!isVowel(s[j])) j--;
            if(i >= j) break;
            swap(s[i], s[j]);
        }
        return s;
    }
    
private:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        auto f = [](char c){return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';};
        int i = 0, j = s.size()-1;
        while(i < j){
            while(i < j && f(s[i]) == false) i++;
            while(i < j && f(s[j]) == false) j--;
            if(i >= j) break;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};