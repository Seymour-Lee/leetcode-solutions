class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto &a: A) a = a * a;
        sort(A.begin(), A.end());
        return A;
    }
};