class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        set<string> ops = {"+", "-", "*", "/"};
        map<string, int(*)(int, int)> op2func = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return a*b;}},
            {"/", [](int a, int b){return a/b;}},
        };
        for(auto token: tokens){
            if(stk.empty() == true){
                stk.push(stoi(token));
                continue;
            }
            if(ops.find(token) != ops.end()){
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(op2func[token](a, b));
            }
            else{
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, int(*)(int, int)> a2b = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return a*b;}},
            {"/", [](int a, int b){return a/b;}},
        };
        stack<int> stk;
        for(auto str: tokens){
            if(a2b.find(str) == a2b.end()) stk.push(stoi(str));
            else{
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                stk.push(a2b[str](a, b));
            }
        }
        return stk.top();
    }
};