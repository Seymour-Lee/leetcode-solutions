class Solution {
public:
    bool checkRecord(string s) {
        if(s.size() <= 1) return true;
        int a = (s[0] == 'A') + (s[1] == 'A');
        if(a == 2) return false;
        for(int i = 2; i < s.size(); i++){
            if(s[i] == 'A') a++;
            if(a > 1 || (s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L')) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool checkRecord(string s) {
        if(s.size() <= 2) return count(s.begin(), s.end(), 'A') != 2;
        int counter = (s[0] == 'A') + (s[1] == 'A');
        for(int i = 2; i < s.size(); i++){
            if(s[i] == 'A') counter++;
            if(counter >= 2 || (s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L')) return false;
        }
        return true;
    }
};