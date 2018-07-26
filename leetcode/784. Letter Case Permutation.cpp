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