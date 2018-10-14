class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0; i < A.size(); i++){
            int j = i;
            while(A[j] % 2 != i % 2) j++;
            swap(A[i], A[j]);
        }
        return A;
    }
};