class Solution {
public:
    bool canWin(string s) {
        if(s.size() < 2) return false;
        for(auto i = 0; i < s.size()-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                string str = s.substr(0, i) + "--" + s.substr(i+2);
                if(canWin(str) == false) return true;
            }
        }
        return false;
    }
};