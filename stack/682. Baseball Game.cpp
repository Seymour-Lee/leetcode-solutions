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

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score = 0;
        vector<int> num;
        int temp = 0;
        int i;
        
        if(!ops.size()) return 0;
        for(i = 0;i < ops.size();i++)
        {
            if(ops[i] == "+"){
                temp = num[num.size()-1] + num[num.size()-2];
                score += temp; 
                num.push_back(temp);
            }
            else if(ops[i] == "D"){
                temp = num[num.size()-1] * 2;
                score +=  temp;
                num.push_back(temp);
            }
            else if(ops[i] == "C"){
                temp = num[num.size()-1];
                score -= temp;
                num.pop_back();
            }
            else{
                temp = atoi(ops[i].c_str());
                score += temp;
                num.push_back(temp);
            }
        }
        
        return score;
    }
};