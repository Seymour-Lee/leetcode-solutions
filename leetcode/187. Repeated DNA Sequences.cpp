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