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