class Solution {
public:
    string countOfAtoms(string formula) {
        recursion(formula, 1);
        string ans = "";
        for(auto p: str2num) ans += p.first + (p.second == 1? "": to_string(p.second));
        return ans;
    }
    
private:
    map<string, int> str2num;
    
    void recursion(string str, int t){
        if(str.size() == 0) return;
        if(str[0] == '(' && str.back() == ')') str = str.substr(1, str.size()-2);
        stack<string> stk;
        for(int i = 0; i < str.size(); i++){
            if('A' <= str[i] && str[i] <= 'Z'){
                if(stk.empty() == false){
                    if(stk.size() == 1){
                        str2num[stk.top()] += 1 * t;
                        stk.pop();
                    }
                    else if(stk.size() == 2){
                        int num = stoi(stk.top());
                        stk.pop();
                        string atom = stk.top();
                        stk.pop();
                        str2num[atom] += num * t;
                    }
                }
                stk.push(string(1, str[i]));
            }
            else if('a' <= str[i] && str[i] <= 'z'){
                stk.top() += string(1, str[i]);
            }
            else if('0' <= str[i] && str[i] <= '9'){
                if('0' <= stk.top()[0] && stk.top()[0] <= '9'){
                    stk.top() += string(1, str[i]);
                }
                else{
                    stk.push(string(1, str[i]));
                }
            }
            else if(str[i] == '('){
                int j = i+1;
                int counter = 1;
                while(counter > 0){
                    if(str[j] == '(') counter++;
                    if(str[j] == ')') counter--;
                    j++;
                }
                string sub = str.substr(i+1, j-i+1-3);
                i = j;
                while(j < str.size() && '0' <= str[j] && str[j] <= '9') j++;
                int times = stoi(str.substr(i, j-i+1));
                recursion(sub, times*t);
                i = j-1;
            }
        }
        if(stk.size() == 1){
            str2num[stk.top()] += 1 * t;
        }
        else if(stk.size() == 2){
            int num = stoi(stk.top());
            stk.pop();
            string atom = stk.top();
            stk.pop();
            str2num[atom] += num * t;
        }
    }
};