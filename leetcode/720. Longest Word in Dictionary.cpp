class Solution {
public:
    string longestWord(vector<string>& words) {
        string result = "";
        set<string> wordset;
        for (auto word: words) wordset.insert(word);
        for (auto word: words) {
            if (word.size() > result.length() || (word.size() == result.size() && word < result)) {
                bool good = true;
                for (int i = 1; i < word.size(); i++) {
                    if (wordset.find(word.substr(0, i)) == wordset.end()) {
                        good = false;
                        break;
                    }
                }
                if (good) result = word;
            }    
        }
        return result;
    }
};