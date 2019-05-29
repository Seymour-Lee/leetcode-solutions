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

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while(i < j){
            if(A[i] % 2 == 0) i++;
            else if(A[j] % 2 == 1) j--;
            else swap(A[i], A[j]);
        }
        return A;
    }
};