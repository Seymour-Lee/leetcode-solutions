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

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans = "";
        bool neg = (num < 0);
        num = abs(num);
        while(num){
            ans += to_string(num%7);
            num /= 7;
        }
        if(neg) ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};