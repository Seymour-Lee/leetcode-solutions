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