class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum = 0;
        for(int i = S.size()-1; i >= 0; sum = (sum + shifts[i--]) % 26)
            S[i] = 'a' + (S[i] - 'a' + sum + shifts[i]) % 26;
        return S;
    }
};