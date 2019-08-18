class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) K--;
            if (K < 0 && A[i++] == 0) K++;
        }
        return j - i;
    }
};

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0;
        int l = 0, r = 0;
        int zeros = 0;
        while(r < A.size()){
            if(A[r]) r++, ans = max(ans, r-l);
            else if(zeros < K) zeros++, r++, ans = max(ans, r-l);
            else zeros -= (A[l++] == 0);
        }
        return ans;
    }
};