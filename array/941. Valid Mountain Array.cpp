class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;
        int i = 0, j = A.size()-1;
        while(i+1 < A.size() && A[i] < A[i+1]) i++;
        while(j-1 >= 0 && A[j-1] > A[j]) j--;
        return i == j && i != 0 && j != A.size()-1;
    }
};

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while(i+1 < A.size() && A[i] < A[i+1]) i++;
        while(j-1 >= 0 && A[j-1] > A[j]) j--;
        return i == j && i != 0 && j != A.size()-1;
    }
};