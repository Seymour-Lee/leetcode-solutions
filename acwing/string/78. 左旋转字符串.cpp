class Solution {
public:
    string leftRotateString(string str, int n) {
        return str.substr(n) + str.substr(0, n);
    }
};