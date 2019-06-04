class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        for(int i = 0; i < num1.size() || i < num2.size(); i++){
            int one = i < num1.size()? num1[i] - '0': 0;
            int two = i < num2.size()? num2[i] - '0': 0;
            result  = to_string((one + two +carry) % 10) + result;
            carry = (one + two + carry) / 10;
        }
        return carry? "1" + result: result;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size()-1, j = num2.size()-1;
        int c = 0;
        while(i >= 0 || j >= 0){
            int a = (i >= 0? num1[i]-'0': 0);
            int b = (j >= 0? num2[j]-'0': 0);
            int s = (a+b+c)%10;
            c = (a+b+c)/10;
            ans += '0'+s;
            i--, j--;
        }
        if(c) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};