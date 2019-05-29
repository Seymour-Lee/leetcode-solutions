class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                                "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
                                "...-",".--","-..-","-.--","--.."};
        set<string> result;
        for(auto word: words){
            string cur = "";
            for(auto c: word) cur += morse[c-'a'];
            result.insert(cur);
        }
        return result.size();
    }
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ch2code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> codes;
        for(auto str: words){
            string code = "";
            for(auto c: str) code += ch2code[c-'a'];
            codes.insert(code);
        }
        return codes.size();
    }
};