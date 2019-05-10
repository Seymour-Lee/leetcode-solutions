class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        for(auto ch: s){
            if(state == 0){
                if(ch == ' ') state = 0;
                else if(ch == '+' || ch == '-') state = 1;
                else if(isdigit(ch)) state = 2;
                else if(ch == '.') state = 9;
                else state = -1;
            }
            else if(state == 1){
                if(isdigit(ch)) state = 2;
                else if(ch == '.') state = 9;
                else state = -1;
            }
            else if(state == 2){
                if('0' <= ch && ch <= '9') state = 2;
                else if(ch == '.') state = 3;
                else if(ch == 'e') state = 5;
                else if(ch == ' ') state = 8;
                else state = -1;
            }
            else if(state == 3){// .
                if('0' <= ch && ch <= '9') state = 4;
                else if(ch == ' ') state = 8;
                else if(ch == 'e') state = 5;
                else state = -1;
            }
            else if(state == 4){// .nums
                if('0' <= ch && ch <= '9') state = 4;
                else if(ch =='e') state = 5;
                else if(ch == ' ') state = 8;
                else state = -1;
            }
            else if(state ==5){ // .nums e
                if(ch == '+' || ch == '-') state = 6;
                else if('0' <= ch && ch <= '9') state = 7;
                else state = -1;
            }
            else if(state == 6){ // .num e +/-
                if('0' <= ch && ch <= '9') state = 7;
                else state = -1;
            }
            else if(state == 7){
                if('0' <= ch && ch <= '9') state = 7;
                else if(ch == ' ') state = 8;
                else state = -1;
            }
            else if(state == 8){
                if(ch == ' ') state = 8;
                else state = -1;
            }
            else if(state == 9){
                if('0' <= ch && ch <= '9') state = 4;
                else state = -1;
            }
            else{
                state = -1;
                break;
            }
        }
        return state == 2 || state == 3 || state == 4 || state == 7 || state == 8;
    }
};