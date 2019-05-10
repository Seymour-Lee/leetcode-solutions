class Solution {
public:
    int firstUniqChar(string s) {
        if(s == "") return -1;
        int result = INT_MAX;
        map<char, int> table;
        for(auto c: s) table[c]++;
        set<char> unique;
        for(auto item: table){
            if(item.second == 1){
                unique.insert(item.first);
            }
        }
        if(unique.empty()) return -1;
        for(int i = 0; i < s.size(); i++){
            if(unique.find(s[i]) != unique.end()){
                result = i;
                break;
            }
        }
        return result;
    }
};