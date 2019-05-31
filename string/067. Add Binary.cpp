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

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1, j = b.size()-1;
        int c = 0;
        while(i >= 0 || j >= 0){
            int aa = i >= 0? a[i]-'0': 0;
            int bb = j >= 0? b[j]-'0': 0;
            int v = (aa+bb+c) % 2;
            c = (aa+bb+c) / 2;
            ans += ('0'+v);
            i--,j--;
        }
        if(c) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};