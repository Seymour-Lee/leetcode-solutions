class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0) return 0;
        vector<string> stk;
        stk.push_back("#");
        unordered_map<string, long(*)(long, long)> op2func = {
            {"+", [](long a, long b){return a+b;}},
            {"-", [](long a, long b){return a-b;}},
            {"*", [](long a, long b){return a*b;}},
            {"/", [](long a, long b){return a/b;}},
        };
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            if(s[i] == '*' || s[i] == '/'){
                stk.push_back(string(1, s[i]));
            }
            else if(s[i] == '('){
                stk.push_back("(");
            }
            else if(s[i] == ')'){ // compute with ()
                vector<string> ops;
                while(stk.back() != "("){
                    ops.push_back(stk.back());
                    stk.pop_back();
                }
                while(ops.size() > 1){
                    long a = stol(ops.back()); ops.pop_back();
                    string op = ops.back(); ops.pop_back();
                    long b = stol(ops.back()); ops.pop_back();
                    ops.push_back(to_string(op2func[op](a, b)));
                }
                stk.pop_back();
                stk.push_back(ops.back());
            }
            else if(s[i] == '+' || s[i] == '-'){
                if(stk.back() == "#" || stk.back() == "("){
                    string num = string(1, s[i]);
                    while(isdigit(s[i+1])) num += string(1, s[++i]);
                    stk.push_back(num);
                }
                else{ // expr
                    stk.push_back(string(1, s[i]));
                }
            }
            else{ // number
                string num = string(1, s[i]);
                while(isdigit(s[i+1])) num += string(1, s[++i]);
                if(stk.back() == "*" || stk.back() == "/"){
                    long b = stol(num);
                    string op = stk.back(); stk.pop_back();
                    long a = stol(stk.back()); stk.pop_back();
                    num = to_string(op2func[op](a, b));
                }
                stk.push_back(num);
            }
        }
        long ans = stol(stk[1]);
        for(int i = 2; i < stk.size(); i+=2){
            string op = stk[i];
            string b = stk[i+1];
            ans = op2func[op](ans, stol(b));
        }
        return (int)ans;
    }
};