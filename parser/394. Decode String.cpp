class Solution {
public:
    string decodeString(string s) {
        if(s == "") return "";
        stack<string> stk;
        for(auto c: s){
            if(isdigit(c)){
                string str = stk.empty() || isdigit(stk.top()[0]) == false? 
                             string(""): stk.top();
                if(stk.empty() == false && isdigit(stk.top()[0])) stk.pop();
                stk.push(str + c);
            }
            else if(c == '['){
                stk.push("[");
            }
            else if(c == ']'){
                string str = stk.top();
                stk.pop();
                stk.pop();
                int re = stoi(stk.top());
                stk.pop();
                string result = "";
                while(re--) result += str;
                while(stk.empty() == false && isalpha(stk.top()[0])){
                    result = stk.top() + result;
                    stk.pop();
                }
                stk.push(result);
            }
            else{
                string str = stk.empty() || stk.top() == "["? 
                             string(""): stk.top();
                if(stk.empty() == false && stk.top() != "[") stk.pop();
                stk.push(str + c);
            }
        }
        return stk.top();
    }
};

class Solution {
public:
    string decodeString(string s) {
        if(s == "") return "";
        stack<string> stk;
        for(auto c: s){
            if(isdigit(c)){
                if(stk.empty() == false && isdigit(stk.top().back())){
                    stk.top() += c;
                }
                else{
                    stk.push(string(1, c));
                }
            }
            else if(c == '['){
                stk.push("[");
            }
            else if(c == ']'){
                string str = stk.top(); stk.pop();
                stk.pop();
                int num = stoi(stk.top()); stk.pop();
                string to = "";
                while(num--) to += str;
                if(stk.empty() == false && isalpha(stk.top().back())){
                    stk.top() += to;
                }
                else{
                    stk.push(to);
                }
            }
            else{
                if(stk.empty() == false && isalpha(stk.top().back())){
                    stk.top() += c;
                }
                else{
                    stk.push(string(1, c));
                }
            }
        }
        return stk.top();
    }
};