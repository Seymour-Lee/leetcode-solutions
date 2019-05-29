class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result;
        int prev = -S.size();
        for(int i = 0; i < S.size(); i++){
            if(S[i] == C) prev = i;
            result.push_back(i-prev);
        }

        prev = 2 * S.size();
        for(int i = S.size()-1; i >= 0; i--){
            if(S[i] == C) prev = i;
            result[i] = min(result[i], prev - i);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> l(S.size(), INT_MAX), r(S.size(), INT_MAX);
        int prev = INT_MIN;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == C) l[i] = i, prev = i;
            else l[i] = prev;
        }
        prev = INT_MAX;
        for(int i = S.size()-1; i >= 0; i--){
            if(S[i] == C) r[i] = i, prev = i;
            else r[i] = prev;
        }
        vector<int> ans;
        for(int i = 0; i < l.size(); i++){
            if(l[i] == INT_MIN) ans.push_back(abs(r[i] - i));
            else if(r[i] == INT_MAX) ans.push_back(abs(l[i]-i));
            else ans.push_back(min(abs(r[i]-i), abs(l[i]-i)));
        }
        return ans;
    }
};