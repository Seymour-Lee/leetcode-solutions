class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        if(A.size() == 0) return 0;
        int ans = 0;
        vector<int> sums(A.size()+1, 0);
        for(int i = 0; i < A.size(); i++) sums[i+1] = sums[i] + A[i];
        for(int i = 0; i+L <= A.size(); i++){
            for(int j = i+L; j+M <= A.size(); j++){
                ans = max(ans, sums[i+L]-sums[i] + sums[j+M]-sums[j]);
            }
        }
        for(int j = 0; j+M <= A.size(); j++){
            for(int i = j+M; i+L <= A.size(); i++){
                ans = max(ans, sums[i+L]-sums[i] + sums[j+M]-sums[j]);
            }
        }
        
        return ans;
    }
};