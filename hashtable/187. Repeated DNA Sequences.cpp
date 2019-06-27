class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size() < 10) return result;
        set<string> cur;
        set<string> repeat;
        for(int i = 0; i <= s.size()-10; i++){
            string str = s.substr(i, 10);
            if(cur.find(str) == cur.end()){ //str did not show up in the past
                cur.insert(str);
            }
            else{ //str showed up
                if(repeat.find(str) == repeat.end()){ // str not in result
                    repeat.insert(str);
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        string str = s.substr(0, 10);
        unordered_map<string, int> strs;
        vector<string> ans;
        strs[str]++;
        for(int i = 10; i < s.size(); i++){
            str = str.substr(1) + s[i];
            strs[str]++;
        }
        for(auto p: strs) if(p.second > 1) ans.push_back(p.first);
        return ans;
    }
};