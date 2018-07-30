class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> patternToWord;
        map<string, char> wordToPattern;
        int i = 0, j = 0;
        for(auto c: pattern){
            if(j >= str.size()) return false;
            while(j < str.size() && str[j] != ' ') j++;
            string s = str.substr(i, j-i);
            j++, i = j;
            map<char, string>::iterator itor1 = patternToWord.find(c);
            map<string, char>::iterator itor2 = wordToPattern.find(s);
            if(itor1 == patternToWord.end() && itor2 == wordToPattern.end()){
                patternToWord[c] = s;
                wordToPattern[s] = c;
            }
            else if(itor1->first == itor2->second && itor1->second == itor2->first){
                continue;
            }
            else{
                return false;
            }
        }
        if(j < str.size()) return false;
        return true;
    }
};