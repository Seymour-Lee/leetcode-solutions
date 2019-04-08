class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if(A.size() == 1) return -1;
        sort(A.begin(), A.end());
        int i = 0, j = A.size()-1;
        int ans = -1;
        while(i < j){
            int cur = A[i]+A[j];
            
            if(ans < cur && cur < K) ans = cur;
            if(cur >= K) j--;
            else i++;
        }
        return ans < K? ans: -1;
    }
};

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if(A.size() == 1) return -1;
        int ans = -1;
        for(int i = 0; i < A.size(); i++){
            for(int j = i+1; j < A.size(); j++){
                if(A[i]+A[j] < K) ans = max(ans, (A[i]+A[j]));
            }
        }
        return ans;
    }
};