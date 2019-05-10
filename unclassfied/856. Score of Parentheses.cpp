class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        for(auto c: S){
            if(c == '('){
                stk.push(0);
            }
            else{
                int cur = stk.top();
                stk.pop();
                int pre = 0;
                if(stk.empty() == false){
                    pre = stk.top();
                    stk.pop();
                }
                stk.push(pre + max(2*cur, 1));
            }
        }
        return stk.top();
    }
};