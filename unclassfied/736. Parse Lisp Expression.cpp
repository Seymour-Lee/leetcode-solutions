class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> memo;
        return recursion(expression, memo);
    }
    
private:
    int recursion(string exp, unordered_map<string, int> memo){
        if ((exp[0] == '-') || (exp[0] >= '0' && exp[0] <= '9')) return stoi(exp);
        else if (exp[0] != '(') return memo[exp];
        //to get rid of the first '(' and the last ')'
        exp = exp.substr(1,exp.size()-2);
        int start = 0;
        string op = parse(exp, start);
        if (op == "let") {
            while (true) {
                string variable = parse(exp, start);
                //if there is no more expression, simply evaluate the variable
                if (start > exp.size())
                    return recursion(variable, memo);
                string temp = parse(exp, start);
                memo[variable] = recursion(temp, memo);                    
            }
        }
        else if (op == "add") return recursion(parse(exp ,start), memo) 
                                   + recursion(parse(exp,start), memo);
        else if (op == "mult") return recursion(parse(exp ,start), memo) 
                                    * recursion(parse(exp,start), memo);
    }
    
    string parse(string &s,int &start) {
        int end = start+1, temp = start, count = 1;
        if (s[start] == '(') {
            while (count != 0) {
                if (s[end] == '(')
                    count++;
                else if (s[end] == ')')
                    count--;
                end++;
            }
        }
        else {
            while (end < s.size() && s[end] != ' ')
                end++;
        }
        start = end+1;
        return s.substr(temp,end-temp);
    }
};