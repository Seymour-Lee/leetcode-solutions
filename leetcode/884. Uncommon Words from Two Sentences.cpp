class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        map<string, int> table;
        vector<string> la = GetList(A);
        vector<string> lb = GetList(B);
        for(auto w: la) table[w]++;
        for(auto w: lb) table[w]++;
        for(auto item: table) if(item.second == 1) result.push_back(item.first);
        return result;
    }
    
private:
    vector<string> GetList(string s){
        vector<string> result;
        while(s != ""){
            int i = 0;
            for(; i < s.size() && s[i] != ' '; i++);
            result.push_back(s.substr(0, i));
            s = i == s.size()? "": s.substr(i+1, s.size()-i-1);
        }
        return result;
    }
};