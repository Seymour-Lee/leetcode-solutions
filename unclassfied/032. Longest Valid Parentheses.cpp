class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> cur = {0};
        int result = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == '(' && s[i]==')'){
                cur.push_back(cur[i-2] + 2);
            }
            else{
                if(cur[i-1] && s[i] == ')' && s[i-cur[i-1]-1] == '('){
                    cur.push_back(cur[i-1] + 2 + cur[i-cur[i-1]-2]);
                }
                else{
                    cur.push_back(0);
                }
            }
            result = cur.back() > result? cur.back(): result;
        }
        return result;
    }
};