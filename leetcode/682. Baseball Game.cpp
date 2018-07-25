class Solution {
public:
    int calPoints(vector<string>& ops) {
        int result;
        stack<int> stk;
        for(auto op: ops){
            if(op == "+"){
                int top = stk.top();
                stk.pop();
                int to_push = top + stk.top();
                stk.push(top);
                stk.push(to_push);
            }
            else if(op == "D"){
                stk.push(2*stk.top());
            }
            else if(op == "C"){
                stk.pop();
            }
            else{
                int sign = 1;
                int num;
                if(op[0] == '-'){
                    op = op.substr(1, op.size()-1);
                    sign = -1;
                }
                stringstream stream(op);
                stream>>num;
                stk.push(sign * num);
            }
        }
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};