class Solution {
public:
    string solveEquation(string equation) {
        equation = "+" + equation;
        auto strs = split(equation);
        int x = 0;
        int val = 0;
        for(auto s: strs){
            if(s.back() == 'x'){
                s.pop_back();
                if(s.size() == 1) s += '1';
                x += stoi(s);
            }
            else{
                val -= stoi(s);
            }
        }
        if(!x && !val) return "Infinite solutions";
        if(!x) return "No solution";
        return "x=" + to_string(val / x);
    }
    
private:
    vector<string> split(string &s){
        vector<string> result(1);
        string op = "+-";
        int flag = 0;
        for(auto c: s){
            if(isDigit(c)){
                result.back() += c;
            }
            else{
                if(!result.back().empty() && isDigit(result.back().back())){
                    result.push_back(string());
                }
                if(c == '=') flag = 1;
                if(c == '-'){
                    result.back() = string(1, op[1-flag]);
                }
                else{
                    result.back() = string(1, op[flag]);
                }
            }
        }
        return result;
    }
    
    bool isDigit(char c){
        return ('0' <= c && c <= '9') || c == 'x';
    }
};

class Solution {
public:
    string solveEquation(string equation) {
        equation = "+" + equation;
        auto strs = split(equation);
        int x = 0;
        int val = 0;
        for(auto s: strs){
            if(s.back() == 'x'){
                s.pop_back();
                if(s.size() == 1) s += '1';
                x += stoi(s);
            }
            else{
                val -= stoi(s);
            }
        }
        if(!x && !val) return "Infinite solutions";
        if(!x) return "No solution";
        return "x=" + to_string(val / x);
    }
    
private:
    vector<string> split(string &s){
        vector<string> result(1);
        string op = "+-";
        int flag = 0;
        for(auto c: s){
            if(isDigit(c)){
                result.back() += c;
            }
            else{
                if(!result.back().empty() && isDigit(result.back().back())){
                    result.push_back(string());
                }
                if(c == '=') flag = 1;
                if(c == '-'){
                    result.back() = string(1, op[1-flag]);
                }
                else{
                    result.back() = string(1, op[flag]);
                }
            }
        }
        return result;
    }
    
    bool isDigit(char c){
        return ('0' <= c && c <= '9') || c == 'x';
    }
};