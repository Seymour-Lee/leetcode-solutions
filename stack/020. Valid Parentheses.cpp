class Solution {
public:
    bool isValid(string s) {
        map<char, char> mapping;
        mapping[')'] = '(';
        mapping[']'] = '[';
        mapping['}'] = '{';
        stack<char> stk;
        stk.push('$');
        
        for(int i = 0; i < s.size(); i++){
            char cur = s.at(i);
            if(stk.top() == mapping[cur]){
                stk.pop();
            }
            else{
                stk.push(cur);
            }
        }
            
        return stk.top() == '$';
    }
};

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> r2l = {{')', '('},
                                         {']', '['},
                                         {'}', '{'}};
        stack<char> stk;
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            if(c == ')' || c == ']' || c == '}'){
                if(stk.empty() == false && r2l[c] == stk.top()) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> r2l = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        for(auto c: s){
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            else{
                if(stk.empty() == false && stk.top() == r2l[c]){
                    stk.pop();
                    continue;
                }
                return false;
            }
        }
        return stk.empty();
    }
};