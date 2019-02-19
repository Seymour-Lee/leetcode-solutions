class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0;
        int i = 0;
        while(i+K <= A.size()){
            // cout<<i<<endl;
            if(A[i] == 1) i++;
            else{
                for(int j = i; j < i+K; j++) A[j] = (A[j] == 0? 1: 0);
                ans++;
            }
        }
        while(i < A.size()) if(A[i++] == 0) return -1;
        return ans;
    }
};