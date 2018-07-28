class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        set<string> s;
        for(auto str: banned){
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            s.insert(str);
        } 
        string result;
        map<string, int> table;
        int i, j;
        for(i = 0, j = 0; i < paragraph.size() && j < paragraph.size(); i = j){
            string str;
            while(j < paragraph.size() && 'a' <= paragraph[j] &&  paragraph[j] <= 'z') j++;
            str = paragraph.substr(i, j-i);
            table[str]++;
            if(j == paragraph.size()) break;
            while(j < paragraph.size() && !('a' <= paragraph[j] &&  paragraph[j] <= 'z')) j++;
        }
        int most = 0;
        for(auto item: table){
            if(item.second > most && s.find(item.first) == s.end()){
                result = item.first;
                most = item.second;
            }
        }
        return result;
    }
};