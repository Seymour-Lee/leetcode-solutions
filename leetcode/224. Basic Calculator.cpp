class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ")";
        map<string, int(*)(int, int)> op2func = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}}};
        stack<string> unusedStrsStack;
        for(auto ch: s){
            if(ch == ' ') continue;
            if(isdigit(ch)){
                string toPush = string(1, ch);
                while(unusedStrsStack.empty() == false && unusedStrsStack.top() != "(" 
                      && unusedStrsStack.top() != "+" && unusedStrsStack.top() != "-"){
                    string prev = unusedStrsStack.top();
                    unusedStrsStack.pop();
                    toPush = prev + toPush;
                }
                unusedStrsStack.push(toPush);
            }
            else if(ch == '(' || ch == '+' || ch == '-'){
                unusedStrsStack.push(string(1, ch));
            }
            else if(ch == ')'){
                stack<string> toCalculateStack;
                while(unusedStrsStack.empty() == false && unusedStrsStack.top() != "("){
                    toCalculateStack.push(unusedStrsStack.top());
                    unusedStrsStack.pop();
                }
                unusedStrsStack.pop();
                while(toCalculateStack.size() >= 3){
                    string a = toCalculateStack.top(); toCalculateStack.pop();
                    string op = toCalculateStack.top(); toCalculateStack.pop();
                    string b = toCalculateStack.top(); toCalculateStack.pop();
                    toCalculateStack.push(to_string(op2func[op](stoi(a), stoi(b))));
                }
                unusedStrsStack.push(toCalculateStack.top());
            }
        }
        return stoi(unusedStrsStack.top());
    }
};