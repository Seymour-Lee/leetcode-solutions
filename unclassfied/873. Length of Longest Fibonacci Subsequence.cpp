class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        if(A.size() < 3) return 0;
        int ans = 0;
        int n = A.size();
        map<int, int> num2idx;
        for(int i = 0; i < n; i++) num2idx[A[i]] = i;
        map<int, int> longest;
        for(int k = 0; k < n; k++){
            for(int j = 0; j < k; j++){
                if(A[k]-A[j] < A[j] && num2idx.count(A[k]-A[j])){
                    int i = num2idx[A[k]-A[j]];
                    longest[j*n+k] = longest[i*n+j]+1;
                    ans = max(ans, longest[j*n+k]+2);
                }
            }
        }
        return ans;
    }
};