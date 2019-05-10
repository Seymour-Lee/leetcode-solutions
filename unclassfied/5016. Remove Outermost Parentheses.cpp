class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        int counter = 0;
        for(auto c: S){
            if(c == '('){
                if(counter != 0) ans += c;
                counter++;
            }
            else{
                counter--;
                if(counter != 0) ans += c;
            }
        }
        
        return ans;
    }
};