class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        stack<string> stk;
        istringstream is(path);
        string str = "";
        while(getline(is, str, '/')){
            if(str != "" && str != "." && str != ".."){
                stk.push(str);
            }
            else if(str == ".." && stk.empty() == false){
                stk.pop();
            }
        }
        while(stk.empty() == false){
            result = "/" + stk.top() + result;
            stk.pop();
        }
        return result == ""? "/": result;
    }
};