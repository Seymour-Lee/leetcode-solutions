class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int length = S.size();
        vector<string> result;
        queue<string> q;
        q.push("");
        transform(S.begin(), S.end(), S.begin(), ::tolower);
        while(S != ""){
            int i = 0;
            for(; i < S.size() && '0' <= S[i] && S[i] <= '9'; i++);
            if(i == S.size()) break;
            string lower = S.substr(0, i+1);
            string upper = lower;
            upper[upper.size()-1] = 'A' - 'a' + upper.back();
            S = S.substr(i+1, S.size()-i-1);
            int size = q.size();
            while(size--){
                string cur = q.front();
                q.pop();
                q.push(cur + lower);
                q.push(cur + upper);
            }
        }
        if(S != ""){
            int size = q.size();
            while(size--){
                string cur = q.front();
                q.pop();
                q.push(cur + S);
            }
        }
        while(q.empty() == false){
            if(q.front().size() == length)
                result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        backtracking(S, 0, ans);
        return ans;
    }
    
private:
    void backtracking(string str, int pos, vector<string> &ans){
        if(pos == str.size()){
            ans.push_back(str);
            return;
        }
        if(isdigit(str[pos])) backtracking(str, pos+1, ans);
        else{
            backtracking(str, pos+1, ans);
            str[pos] = ('a' <= str[pos] && str[pos] <= 'z'? str[pos] + 'A'-'a': str[pos] + 'a'-'A');
            backtracking(str, pos+1, ans);
        }
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        unordered_set<string> seen;
        backtracking(seen, S, 0, "");
        return vector<string>(seen.begin(), seen.end());
    }
    
private:
    void backtracking(unordered_set<string> &seen, string s, int pos, string cur){
        if(pos == s.size()){
            seen.insert(cur);
            return;
        }
        if(isdigit(s[pos])) backtracking(seen, s, pos+1, cur+s[pos]);
        else{
            char c = tolower(s[pos]);
            backtracking(seen, s, pos+1, cur+c);
            backtracking(seen, s, pos+1, cur+(char)toupper(c));
        }
    }
};