class Solution {
public:
    int calculate(string s) {
        auto isnumber = [](char c){return c == ' ' || isdigit(c);};
        stack<string> stk;
        map<string, int(*)(int,int)> op2func = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return a*b;}},
            {"/", [](int a, int b){return a/b;}},
        };
        for(auto it = s.begin(); it != s.end(); ){
            const char &ch = (*it);
            if(isnumber(ch)){
                auto it2 = find_if_not(it, s.end(), isnumber);
                string b = deleteSpace(string(it, it2));
                if(stk.empty() == false && (stk.top() == "*" || stk.top() == "/")){
                    string op = stk.top(); stk.pop();
                    string a = stk.top(); stk.pop();
                    b = to_string(op2func[op](stoi(a), stoi(b)));
                }
                stk.push(b);
                it = it2;
            }
            else{
                stk.push(string(1, ch));
                it++;
            }
        }
        stk = reverseStack(stk);
        while(stk.size() > 1){
            int a = stoi(stk.top()); stk.pop();
            string op = stk.top(); stk.pop();
            int b = stoi(stk.top()); stk.pop();
            stk.push(to_string(op2func[op](a, b)));
        }
        return stoi(stk.top());
    }
    
private:
    string deleteSpace(string str){
        string ans = "";
        for(auto c: str) ans += isdigit(c)? string(1, c): string("");
        return ans;
    }
    
    stack<string> reverseStack(stack<string> stk){
        stack<string> ans;
        while(stk.empty() == false){
            ans.push(stk.top());
            stk.pop();
        }
        return ans;
    }
};  

class Solution {
public:
    int calculate(string s) {
        stack<string> stk;
        unordered_map<string, int(*)(int,int)> op2func = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return a*b;}},
            {"/", [](int a, int b){return a/b;}},
        };
        for(int i = 0; i < s.size(); i++) if(s[i] != ' '){
            if(isdigit(s[i])){
                if(stk.size() && isdigit(stk.top()[0])) stk.top() += s[i];
                else stk.push(string(1, s[i]));
            }
            else if(s[i] == '+' || s[i] == '-'){
                stk.push(string(1, s[i]));
            }
            else{
                int a = stoi(stk.top()); stk.pop();
                string op = string(1, s[i]);
                string str = "";
                i++;
                while(i < s.size() && (isdigit(s[i]) || s[i] == ' ')) str += s[i++];
                i--;
                int b = stoi(str);
                stk.push(to_string(op2func[op](a, b)));
            }
        }
        stack<string> ss;
        while(stk.empty() == false) ss.push(stk.top()), stk.pop();
        while(ss.size() > 1){
            int a = stoi(ss.top()); ss.pop();
            string op = ss.top(); ss.pop();
            int b = stoi(ss.top()); ss.pop();
            ss.push(to_string(op2func[op](a, b)));
        }
        return stoi(ss.top());
    }
};