class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 1) return false;
        for(int i = 1; i <= s.size() / 2; i++){
            if((s.size() % i) == 0){
                int re = s.size() / i;
                string sub = s.substr(0, i);
                string str = "";
                while(re--) str += sub;
                if(s == str) return true;
            }
        }
        return false;
    }
};