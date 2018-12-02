class Solution {
public:
    string reverseString(string s) {
        string result = "";
        stack<char> stk;
        for(auto c: s) stk.push(c);
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};

class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++, j--) swap(s[i], s[j]);
        return s;
    }
};