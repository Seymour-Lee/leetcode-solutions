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