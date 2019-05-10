class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() > t.size()) swap(s, t);
        if(s.size() == t.size()) return replace(s, t);
        if(s.size()+1 == t.size()) return insert(s, t);
        return false;
    }
    
private:
    bool replace(string s, string t){
        bool modified = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                if(modified == true) return false;
                modified = true;
            }
        }
        return modified;
    }
    
    bool insert(string s, string t){
        if(s == "") return true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                return s.substr(i) == t.substr(i+1);
            }
        }
        return true;
    }
};