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

class Solution {
public:
    int lengthOfLastWord(string s) {        
        istringstream is(s);
        string str;
        string ans;
        while(getline(is, str, ' ')){
            if(str != "") ans = str;
        }
        return ans.size();
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.size() && s.back() == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        return s.find(' ') == string::npos? s.size(): s.find(' ');
    }
};