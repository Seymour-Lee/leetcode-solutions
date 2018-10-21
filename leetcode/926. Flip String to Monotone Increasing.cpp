class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> ones(S.size(), 0);
        vector<int> zeros(S.size(), 0);
        ones[0] = (S[0] == '1'? 1: 0);
        zeros.back() = (S.back() == '0'? 1: 0);
        for(int i = 1; i < S.size(); i++) ones[i] = (S[i] == '1'? ones[i-1]+1: ones[i-1]);
        for(int i = S.size()-2; i >= 0; i--) zeros[i] = (S[i] == '0'? zeros[i+1]+1: zeros[i+1]);
        int ans = INT_MAX;
        for(int i = 0; i < ones.size()-1; i++) ans = min(ans, ones[i]+zeros[i+1]);
        return min(ans, min(ones.back(), zeros.front()));
    }
};