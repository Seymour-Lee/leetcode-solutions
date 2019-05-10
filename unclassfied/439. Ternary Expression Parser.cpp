class Solution {
public:
    string parseTernary(string expression) {
        if(expression.find('?') == string::npos) return expression;
        int pos = 0;
        while(pos < expression.size() && expression[pos] != '?') pos++;
        string boolexpr = expression.substr(0, pos++);
        int counter = 1;
        expression = expression.substr(pos);
        pos = 0;
        while(pos < expression.size()){
            if(expression[pos] == '?') counter++;
            if(expression[pos] == ':') counter--;
            if(counter == 0 && expression[pos] == ':') break;
            pos++;
        }
        string one = expression.substr(0, pos++);
        string two = expression.substr(pos);
        return boolexpr == "T"? parseTernary(one): parseTernary(two);
    }
};