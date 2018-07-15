class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        while(m >= 0 || n >= 0){
            int one = m >= 0? a[m--] - '0': 0;
            int two = n >= 0? b[n--] - '0': 0;
            int sum = one + two + carry;
            carry = sum / 2;
            string cur = (sum % 2) == 0? "0": "1";
            result = cur + result;
        }
        
        if(carry) result = "1" + result;
        
        return result;
    }
};