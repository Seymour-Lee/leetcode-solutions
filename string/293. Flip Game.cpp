class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if(s.size() <= 1) return {};
        set<string> seen;
        for(int i = 0; i < (int)s.size()-1; i++){
            if(s[i] == s[i+1] && s[i] == '+') 
                seen.insert(s.substr(0, i) + "--" 
                            + (i+2 >= s.size()? "": s.substr(i+2)));
        }
        return vector<string>(seen.begin(), seen.end());
    }
};

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if(s.size() < 2) return {};
        vector<string> ans;
        for(int i = 0; i < s.size()-1; i++) if(s[i] == '+' && s[i+1] == '+'){
            ans.push_back(s.substr(0, i)+"--"+s.substr(i+2));
        }
        return ans;
    }
};