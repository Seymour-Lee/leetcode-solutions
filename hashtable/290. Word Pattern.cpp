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

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};