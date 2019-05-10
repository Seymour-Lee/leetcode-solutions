class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int minima = *min_element(A.begin(), A.end());
        string str = to_string(minima);
        int ans = 0;
        for(auto c: str) ans += c-'0';
        return ans %2 == 1? 0: 1;
    }
};