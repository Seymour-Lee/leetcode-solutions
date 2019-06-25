class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        if(strings.size() == 0) return ans;
        vector<string> patterns(strings.size(), "0");
        for(auto i = 0; i < strings.size(); i++){
            char first = strings[i][0];
            for(auto j = 1; j < strings[i].size(); j++){
                patterns[i] += "," + to_string((strings[i][j]+26-first)%26);
            }
        }
        map<string, vector<string>> p2strs;
        for(auto i = 0; i < strings.size(); i++){
            p2strs[patterns[i]].push_back(strings[i]);
        }
        for(auto p: p2strs) ans.push_back(p.second);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> p2s;
        for(auto str: strings){
            string p = "";
            for(int i = 1; i < str.size(); i++) p += (str[i]+26-str[i-1])%26;
            p2s[p].push_back(str);
        }
        for(auto p: p2s) ans.push_back(p.second);
        return ans;
    }
};