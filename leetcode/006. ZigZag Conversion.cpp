class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        for(auto c: s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows-1) goingDown = !goingDown;
            curRow += goingDown? 1: -1;
        }
        for(string row: rows) ans += row;
        return ans;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1) return s;
        vector<string> rows(min((int)s.size(), numRows), "");
        bool down = true;
        int r = 0;
        for(auto c: s){
            if(down){
                if(r < numRows) rows[r++] += c;
                else down = false, r = r-2, rows[r--] += c;
            }
            else{
                if(r >= 0) rows[r--] += c;
                else down = true, r = r+2, rows[r++] += c;
            }
        }
        for(auto str: rows) ans += str;
        return ans;
    }
};