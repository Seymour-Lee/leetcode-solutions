class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length(); 
        string ans = ""; 
        for (int i=min(n1, n2); i >= 1; i--) { 
            string base = s1.substr(0, i); 
            if (isCommonBase(base, s1, s2)) return base;
        } 
        return ans; 
    }
    
    bool isCommonBase(string base, string s1, string s2) {
        if(s1.size() % base.size() != 0 || s2.size() % base.size() != 0) return false;
        for (int j = 0; j < s1.length(); ++j)  
            if (base[j % base.length()] != s1[j]) 
                return false; 
        for (int j = 0; j < s2.length(); ++j)  
            if (base[j % base.length()] != s2[j]) 
                return false;     
        return true; 
    } 
};


