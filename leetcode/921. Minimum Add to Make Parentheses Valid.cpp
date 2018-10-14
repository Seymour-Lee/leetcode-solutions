class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        for(auto ch: S){
            if(stk.size() == 0) stk.push(ch);
            else if(stk.top() == '(' && ch == ')') stk.pop();
            else stk.push(ch);
        }
        return stk.size();
    }
};