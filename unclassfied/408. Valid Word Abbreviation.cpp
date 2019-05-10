class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        for(int j = 0; j < abbr.size(); ){
            if(isdigit(abbr[j]) == false){
                if(word[i++] != abbr[j++]) return false;
                continue;
            }
            int nextj = j;
            while(nextj < abbr.size() && isdigit(abbr[nextj])) nextj++;
            int num = stoi(abbr.substr(j, nextj-j));
            if(num == 0 || to_string(num) != abbr.substr(j, nextj-j)) return false;
            i += num;
            if(i > word.size()) return false;
            j = nextj;
        }
        return i == word.size();
    }
};