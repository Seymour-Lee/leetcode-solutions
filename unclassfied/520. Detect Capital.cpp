class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word == "" || word.size() == 1) return true;
        if('a' <= word[0] && word[0] <= 'z'){ //leetcode
            for(int i = 1; i < word.size(); i++){
                if('A' <= word[i] && word[i] <= 'Z') return false;
            }
        }
        else if('a' <= word[1] && word[1] <= 'z'){ //Google
            for(int i = 2; i < word.size(); i++){
                if('A' <= word[i] && word[i] <= 'Z') return false;
            }
        }
        else{ //USA
            for(int i = 2; i < word.size(); i++){
                if('a' <= word[i] && word[i] <= 'z') return false;
            }
        }
        return true;
    }
};