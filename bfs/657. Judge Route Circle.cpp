class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0;
        int down = 0;
        for(auto c: moves){
            if(c == 'U') down--;
            else if(c == 'D') down++;
            else if(c == 'R') left--;
            else if(c == 'L') left++;
        }
        return left == 0 && down == 0;
    }
};

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto c: moves){
            if(c == 'R') x++;
            if(c == 'L') x--;
            if(c == 'U') y++;
            if(c == 'D') y--;
        }
        return x == 0 && y == 0;
    }
};