class Solution {
public:
    int newInteger(int n) {
        string ans = "";
        while(n) ans += string(1, '0'+(n%9)), n = n / 9;
        return stoi(string(ans.rbegin(), ans.rend()));
    }
};