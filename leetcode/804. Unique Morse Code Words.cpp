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