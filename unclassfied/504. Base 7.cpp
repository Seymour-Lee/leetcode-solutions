class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string result;
        bool negative = num < 0;
        num = num < 0? -1*num: num;
        while(num){
            int remain = num % 7;
            num = num / 7;
            result = to_string(remain) + result;
        }
        return negative? "-"+result: result;
    }
};