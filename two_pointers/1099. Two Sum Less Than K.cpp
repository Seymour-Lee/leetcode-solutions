class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0, j = A.size()-1;
        int ans = -1;
        while(i < j) {
            if(A[i] + A[j] < K) ans = max(ans, A[i++]+A[j]);
            else j--;
        }
        return ans;
    }
};