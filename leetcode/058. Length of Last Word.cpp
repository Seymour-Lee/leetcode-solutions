class Solution {
public:
    int lengthOfLastWord(string s) {        
        string::iterator itor;
        for(itor = s.end()-1; itor != s.begin() && *itor == ' '; itor--);
        s = string(s.begin(), itor+1);
        
        if(s.empty()) return 0;
        
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ') return s.size() - i - 1;
        }
        
        return s.size();
    }
};