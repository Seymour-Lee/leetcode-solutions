class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l < r){
            while(A[l] % 2 == 0) l++;
            while(A[r] % 2 == 1) r--;
            if(l >= r) break;
            swap(A[l++], A[r--]);
        }
        return A;
    }
};