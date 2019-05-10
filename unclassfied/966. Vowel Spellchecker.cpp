class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<int, vector<string>> len2words;
        for(auto str: wordlist) len2words[str.size()].push_back(str);
        unordered_map<string, vector<string>> lower2word;
        unordered_map<string, vector<string>> vowel2word;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto tolower = [](string str){
            for(auto &c: str) if('A' <= c && c <= 'Z') c = 'a' - 'A' + c;
            return str;
        };
        for(auto str: wordlist){
            string lower = tolower(str);
            lower2word[lower].push_back(str);
            for(auto &c: lower) if(vowels.find(c) != vowels.end()) c = '#';
            vowel2word[lower].push_back(str);
        }
        vector<string> ans;
        for(auto str: queries){
            if(len2words.find(str.size()) == len2words.end()){
                ans.push_back("");
                continue;
            }
            if(words.find(str) != words.end()){
                ans.push_back(str);
                continue;
            }
            string lower = tolower(str);
            if(lower2word.find(lower) != lower2word.end()){
                ans.push_back(lower2word[lower].front());
                continue;
            }
            for(auto &c: lower) if(vowels.find(c) != vowels.end()) c = '#';
            if(vowel2word.find(lower) != vowel2word.end()){
                ans.push_back(vowel2word[lower].front());
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};